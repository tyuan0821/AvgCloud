#include <avgserver.h>

AVGserver::AVGserver(utility::string_t url) : m_listener(url)
{
    m_listener.support(methods::GET, std::bind(&AVGserver::handle_get, this, std::placeholders::_1));
    open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << url << std::endl;
}

AVGserver::~AVGserver()
{
   close().wait();
}

/*void AVGserver::handle_error(pplx::task<void>& t)
{
    try
    {
        t.get();
    }
    catch(...)
    {
        // Ignore the error, Log it if a logger is available
    }
}*/


//
// Get Request 
//
void AVGserver::handle_get(http_request message)
{
    auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
    message.relative_uri().path();
    if(message.headers().content_type() == U("application/json"))
    {
	message.reply(status_codes::OK, json::value(get_auth_vector(extract_message_body(message))) )
	.then([message](pplx::task<void> t)
	{
	    try
	    {
	        t.get();
	    }
	        catch(...)
	    {
	        message.reply(status_codes::InternalError,U("INTERNAL ERROR "));
	    }
	  });
    }
    else
    message.reply(status_codes::BadRequest,U("BAD REQUEST"));
    return;
};

json::value AVGserver::extract_message_body(http_request message)
{  
    pplx::task<json::value> extraction = message.extract_json();

    return extraction.get();
}

json::value AVGserver::get_auth_vector(json::value param)
{
    for(auto it = param.as_object().cbegin(); it != param.as_object().cend(); ++it)
    {
        const utility::string_t field = it->first;
        const json::value &value = it->second;

        ucout << field << " " << value.serialize() << std::endl;
    }

    json::value avgVector;
    avgVector["authenticationVectorType"] = json::value::number(HSS_AvgAuthVectorsTypeDt::HSS_AvgAuthVectorsTypeDt_INTERNAL::quintetsE);
    avgVector["rand"] = json::value("00000000000000000000000000");
    avgVector["xres"] = json::value("00001111100000000000000000");
    avgVector["ck"] = json::value("00001111100000022222000000");
    avgVector["ik"] = json::value("00001111100000022222003333");
    avgVector["autn"] = json::value("aaaa1111100bb0022222cc3333");
    ucout << "Sent generated Authentication Vector" << std::endl;
    return avgVector;
}

