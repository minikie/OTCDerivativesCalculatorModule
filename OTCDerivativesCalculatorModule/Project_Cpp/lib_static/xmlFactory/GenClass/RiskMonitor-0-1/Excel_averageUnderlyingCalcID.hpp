// Excel_averageUnderlyingCalcID.hpp 
#ifndef FpmlSerialized_Excel_averageUnderlyingCalcID_hpp
#define FpmlSerialized_Excel_averageUnderlyingCalcID_hpp

#include <ISerialized.hpp>
#include <RiskMonitor-0-1/Excel_selectedUnderlying.hpp>
#include <built_in_type/XsdTypeToken.hpp>

namespace FpmlSerialized {

class Excel_averageUnderlyingCalcID : public ISerialized { 
   public: 
       Excel_averageUnderlyingCalcID(TiXmlNode* xmlNode);

       bool isExcel_selectedUnderlying(){return this->excel_selectedUnderlyingIsNull_;}
       std::vector<boost::shared_ptr<Excel_selectedUnderlying>> getExcel_selectedUnderlying();


       bool isEventDate(){return this->eventDateIsNull_;}
       boost::shared_ptr<XsdTypeToken> getEventDate();


       bool isWeight(){return this->weightIsNull_;}
       std::vector<boost::shared_ptr<XsdTypeToken>> getWeight();


   protected: 
       std::vector<boost::shared_ptr<Excel_selectedUnderlying>> excel_selectedUnderlying_;
       
       bool excel_selectedUnderlyingIsNull_;
       boost::shared_ptr<XsdTypeToken> eventDate_;
       
       bool eventDateIsNull_;
       std::vector<boost::shared_ptr<XsdTypeToken>> weight_;
       
       bool weightIsNull_;

};

} //namespaceFpmlSerialized end
#endif

