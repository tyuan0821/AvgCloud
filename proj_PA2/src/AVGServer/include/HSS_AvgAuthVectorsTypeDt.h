#ifndef HSS_AvgAuthVectorsTypeDt_hh
#define HSS_AvgAuthVectorsTypeDt_hh


////////////////////////////////////////////////////////////////////////////////
//
// TYPE: HSS_AvgAuthVectorsTypeDt
//

class HSS_AvgAuthVectorsTypeDt
{
public:
      enum HSS_AvgAuthVectorsTypeDt_INTERNAL
      {
         quintetsE,
	 tripletsE
      };
      HSS_AvgAuthVectorsTypeDt (HSS_AvgAuthVectorsTypeDt::HSS_AvgAuthVectorsTypeDt_INTERNAL);
      HSS_AvgAuthVectorsTypeDt ();
     ~HSS_AvgAuthVectorsTypeDt ();
};
#endif
