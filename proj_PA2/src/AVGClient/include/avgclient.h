#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

#include <HSS_AvgUserIdTypeDt.h>
#include <HSS_AvgResynchInfoDt.h>
#include <HSS_AvgReqNodeTypeDt.h>

#include <string>
#include <iostream>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

class AVGClient
{
   public:
	AVGClient(const uri& base_uri) : client(base_uri){}
	void sendHttpRequest(const uri_builder& builder, const json::value& value);
	json::value constructJsonObject
	            (std::string userId,
	            HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL userIdType,
		    HSS_AvgResynchInfoDt resynchInfo,
	            int numberOfAV,
		    HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL requestNodeType);

   private:
   	http_client client;
};
