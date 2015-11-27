// FxAverageRateObservationSchedule.cpp 
#include "FxAverageRateObservationSchedule.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

FxAverageRateObservationSchedule::FxAverageRateObservationSchedule(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //startDateNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* startDateNode = xmlNode->FirstChildElement("startDate");

   if(startDateNode){startDateIsNull_ = false;}
   else{startDateIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- startDateNode , address : " << startDateNode << std::endl;
   #endif
   if(startDateNode)
   {
      if(startDateNode->Attribute("href") || startDateNode->Attribute("id"))
      {
          if(startDateNode->Attribute("id"))
          {
             startDateIDRef_ = startDateNode->Attribute("id");
             startDate_ = boost::shared_ptr<XsdTypeDate>(new XsdTypeDate(startDateNode));
             startDate_->setID(startDateIDRef_);
             IDManager::instance().setID(startDateIDRef_,startDate_);
          }
          else if(startDateNode->Attribute("href")) { startDateIDRef_ = startDateNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { startDate_ = boost::shared_ptr<XsdTypeDate>(new XsdTypeDate(startDateNode));}
   }

   //endDateNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* endDateNode = xmlNode->FirstChildElement("endDate");

   if(endDateNode){endDateIsNull_ = false;}
   else{endDateIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- endDateNode , address : " << endDateNode << std::endl;
   #endif
   if(endDateNode)
   {
      if(endDateNode->Attribute("href") || endDateNode->Attribute("id"))
      {
          if(endDateNode->Attribute("id"))
          {
             endDateIDRef_ = endDateNode->Attribute("id");
             endDate_ = boost::shared_ptr<XsdTypeDate>(new XsdTypeDate(endDateNode));
             endDate_->setID(endDateIDRef_);
             IDManager::instance().setID(endDateIDRef_,endDate_);
          }
          else if(endDateNode->Attribute("href")) { endDateIDRef_ = endDateNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { endDate_ = boost::shared_ptr<XsdTypeDate>(new XsdTypeDate(endDateNode));}
   }

   //calculationPeriodFrequencyNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* calculationPeriodFrequencyNode = xmlNode->FirstChildElement("calculationPeriodFrequency");

   if(calculationPeriodFrequencyNode){calculationPeriodFrequencyIsNull_ = false;}
   else{calculationPeriodFrequencyIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- calculationPeriodFrequencyNode , address : " << calculationPeriodFrequencyNode << std::endl;
   #endif
   if(calculationPeriodFrequencyNode)
   {
      if(calculationPeriodFrequencyNode->Attribute("href") || calculationPeriodFrequencyNode->Attribute("id"))
      {
          if(calculationPeriodFrequencyNode->Attribute("id"))
          {
             calculationPeriodFrequencyIDRef_ = calculationPeriodFrequencyNode->Attribute("id");
             calculationPeriodFrequency_ = boost::shared_ptr<CalculationPeriodFrequency>(new CalculationPeriodFrequency(calculationPeriodFrequencyNode));
             calculationPeriodFrequency_->setID(calculationPeriodFrequencyIDRef_);
             IDManager::instance().setID(calculationPeriodFrequencyIDRef_,calculationPeriodFrequency_);
          }
          else if(calculationPeriodFrequencyNode->Attribute("href")) { calculationPeriodFrequencyIDRef_ = calculationPeriodFrequencyNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { calculationPeriodFrequency_ = boost::shared_ptr<CalculationPeriodFrequency>(new CalculationPeriodFrequency(calculationPeriodFrequencyNode));}
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
boost::shared_ptr<XsdTypeDate> FxAverageRateObservationSchedule::getStartDate()
{
   if(!this->startDateIsNull_){
        if(startDateIDRef_ != ""){
             return boost::shared_static_cast<XsdTypeDate>(IDManager::instance().getID(startDateIDRef_));
        }else{
             return this->startDate_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<XsdTypeDate>();
   }
}
boost::shared_ptr<XsdTypeDate> FxAverageRateObservationSchedule::getEndDate()
{
   if(!this->endDateIsNull_){
        if(endDateIDRef_ != ""){
             return boost::shared_static_cast<XsdTypeDate>(IDManager::instance().getID(endDateIDRef_));
        }else{
             return this->endDate_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<XsdTypeDate>();
   }
}
boost::shared_ptr<CalculationPeriodFrequency> FxAverageRateObservationSchedule::getCalculationPeriodFrequency()
{
   if(!this->calculationPeriodFrequencyIsNull_){
        if(calculationPeriodFrequencyIDRef_ != ""){
             return boost::shared_static_cast<CalculationPeriodFrequency>(IDManager::instance().getID(calculationPeriodFrequencyIDRef_));
        }else{
             return this->calculationPeriodFrequency_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<CalculationPeriodFrequency>();
   }
}
}
