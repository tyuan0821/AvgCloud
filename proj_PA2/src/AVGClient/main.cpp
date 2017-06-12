#include <avgclient.h>

int main()
{
   AVGClient client(U("http://172.17.0.3:34468"));
   uri_builder builder(U("/"));

/*providing sample values for request*/
   std::string userId = "tao.yuan";

   HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL userIdType = HSS_AvgUserIdTypeDt::HSS_AvgUserIdTypeDt_INTERNAL::usimE;
   
   HSS_AvgResynchInfoDt resynchInfo;
   resynchInfo.rand = "111111";
   resynchInfo.auts = "8347883275";
   
   int numberOfAVs = 1;
   
   HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL requestNodeType = HSS_AvgReqNodeTypeDt::HSS_AvgReqNodeTypeDt_INTERNAL::cscfE;
   
   json::value params = client.constructJsonObject(userId, userIdType, resynchInfo, numberOfAVs,requestNodeType);

   client.sendHttpRequest(builder,params);
   return 0;
}
