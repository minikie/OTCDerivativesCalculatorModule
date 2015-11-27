// Excel_returnCalcInfo_CallableOption.hpp 
#ifndef FpmlSerialized_Excel_returnCalcInfo_CallableOption_hpp
#define FpmlSerialized_Excel_returnCalcInfo_CallableOption_hpp

#include <ISerialized.hpp>
#include <RiskMonitor-0-1/Excel_returnCalcInfo.hpp>

namespace FpmlSerialized {

class Excel_returnCalcInfo_CallableOption : public ISerialized { 
   public: 
       Excel_returnCalcInfo_CallableOption(TiXmlNode* xmlNode);

       bool isExcel_returnCalcInfo(){return this->excel_returnCalcInfoIsNull_;}
       boost::shared_ptr<Excel_returnCalcInfo> getExcel_returnCalcInfo();


   protected: 
       boost::shared_ptr<Excel_returnCalcInfo> excel_returnCalcInfo_;
       
       bool excel_returnCalcInfoIsNull_;

};

} //namespaceFpmlSerialized end
#endif

