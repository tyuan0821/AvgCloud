#include <avgclient.h>

void AVGClient::sendHttpRequest(const uri_builder& builder, const json::value& value)
{
    uri_builder requestParam = builder;

/* send HTTP GET request and process the response with use of lambda expression */
    pplx::task<void> requestTask = client.request(methods::GET, requestParam.to_string(), value)
    .then([](http_response response)
    {
        ucout << "Received response status code: " << response.status_code() << "\n";
        pplx::task<json::value> extraction = response.extract_json();
	json::value generatedAV = extraction.get();
	ucout << "avgVector.authenticationVectorType =\t" << generatedAV["authenticationVectorType"].as_integer() << "\n";
	ucout << "avgVector.rand =\t" << generatedAV["rand"].as_string() << "\n";
	ucout << "avgVector.xres =\t" << generatedAV["xres"].as_string() << "\n";
	ucout << "avgVector.ck =\t" << generatedAV["ck"].as_string() << "\n";
	ucout << "avgVector.ik =\t" << generatedAV["ik"].as_string() << "\n";
	ucout << "avgVector.autn =\t" << generatedAV["autn"].as_string() << "\n";
    });

        /* Wait for all the outstanding I/O to complete and handle any exceptions */
    try
    {
        requestTask.wait();
    }
        catch (const std::exception &e)
    {
        ucout << "Error exception: " << e.what() << "\n";
    }
}

/* construct JSON object from given parameters, allows to send all data as one object in one request */

json::value AVGClient::constructJsonObject
	(std::string userId,
	HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL userIdType,
	HSS_AvgResynchInfoDt resynchInfo,
	int numberOfAVs, HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL requestNodeType)
{
    json::value object = json::value::object();
    object[U("userId")] = json::value::string(userId);
    object[U("userIdType")] = json::value::number(userIdType);
    object[U("resynchInfo:rand")] = json::value::string(resynchInfo.rand);
    object[U("resynchInfo:auts")] = json::value::string(resynchInfo.auts);
    object[U("numberOfAVs")] = json::value::number(numberOfAVs);
    object[U("requestNodeType")] = json::value::number(requestNodeType);

    return object;
}
