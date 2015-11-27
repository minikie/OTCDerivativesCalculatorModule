// Excel_multiCondi_multiRng_structuredAccrualCouponSchedule.hpp 
#ifndef FpmlSerialized_Excel_multiCondi_multiRng_structuredAccrualCouponSchedule_hpp
#define FpmlSerialized_Excel_multiCondi_multiRng_structuredAccrualCouponSchedule_hpp

#include <ISerialized.hpp>
#include <built_in_type/XsdTypeToken.hpp>
#include <RiskMonitor-0-1/Excel_multi_rangeND.hpp>
#include <RiskMonitor-0-1/Excel_returnCalcInfo.hpp>

namespace FpmlSerialized {

class Excel_multiCondi_multiRng_structuredAccrualCouponSchedule : public ISerialized { 
   public: 
       Excel_multiCondi_multiRng_structuredAccrualCouponSchedule(TiXmlNode* xmlNode);

       bool isEventDate(){return this->eventDateIsNull_;}
       boost::shared_ptr<XsdTypeToken> getEventDate();


       bool isPayoffDate(){return this->payoffDateIsNull_;}
       boost::shared_ptr<XsdTypeToken> getPayoffDate();


       bool isCalculationStartDate(){return this->calculationStartDateIsNull_;}
       boost::shared_ptr<XsdTypeToken> getCalculationStartDate();


       bool isCalculationEndDate(){return this->calculationEndDateIsNull_;}
       boost::shared_ptr<XsdTypeToken> getCalculationEndDate();


       bool isDescription(){return this->descriptionIsNull_;}
       boost::shared_ptr<XsdTypeToken> getDescription();


       bool isVba_description(){return this->vba_descriptionIsNull_;}
       boost::shared_ptr<XsdTypeToken> getVba_description();


       bool isExcel_multi_rangeND(){return this->excel_multi_rangeNDIsNull_;}
       std::vector<boost::shared_ptr<Excel_multi_rangeND>> getExcel_multi_rangeND();


       bool isExcel_returnCalcInfo(){return this->excel_returnCalcInfoIsNull_;}
       std::vector<boost::shared_ptr<Excel_returnCalcInfo>> getExcel_returnCalcInfo();


       bool isDayCounter(){return this->dayCounterIsNull_;}
       boost::shared_ptr<XsdTypeToken> getDayCounter();


       bool isDetailScheduleType(){return this->detailScheduleTypeIsNull_;}
       boost::shared_ptr<XsdTypeToken> getDetailScheduleType();


   protected: 
       boost::shared_ptr<XsdTypeToken> eventDate_;
       
       bool eventDateIsNull_;
       boost::shared_ptr<XsdTypeToken> payoffDate_;
       
       bool payoffDateIsNull_;
       boost::shared_ptr<XsdTypeToken> calculationStartDate_;
       
       bool calculationStartDateIsNull_;
       boost::shared_ptr<XsdTypeToken> calculationEndDate_;
       
       bool calculationEndDateIsNull_;
       boost::shared_ptr<XsdTypeToken> description_;
       
       bool descriptionIsNull_;
       boost::shared_ptr<XsdTypeToken> vba_description_;
       
       bool vba_descriptionIsNull_;
       std::vector<boost::shared_ptr<Excel_multi_rangeND>> excel_multi_rangeND_;
       
       bool excel_multi_rangeNDIsNull_;
       std::vector<boost::shared_ptr<Excel_returnCalcInfo>> excel_returnCalcInfo_;
       
       bool excel_returnCalcInfoIsNull_;
       boost::shared_ptr<XsdTypeToken> dayCounter_;
       
       bool dayCounterIsNull_;
       boost::shared_ptr<XsdTypeToken> detailScheduleType_;
       
       bool detailScheduleTypeIsNull_;

};

} //namespaceFpmlSerialized end
#endif

