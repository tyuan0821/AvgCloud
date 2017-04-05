#ifndef AVGSERVER_H
#define AVGSERVER_H

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>

#include <HSS_AvgAuthVectorsTypeDt.h>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

class AVGserver
{
    public:
        AVGserver(utility::string_t url);
        ~AVGserver();

        pplx::task<void>open(){return m_listener.open();}
        pplx::task<void>close(){return m_listener.close();}

    private:
        void handle_get(http_request message);
        void handle_error(pplx::task<void>& t);
	json::value extract_message_body(http_request message);
	json::value get_auth_vector(json::value param);
        http_listener m_listener;
};

#endif


