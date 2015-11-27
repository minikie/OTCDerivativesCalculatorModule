// Period.cpp 
#include "Period.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

Period::Period(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //periodMultiplierNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* periodMultiplierNode = xmlNode->FirstChildElement("periodMultiplier");

   if(periodMultiplierNode){periodMultiplierIsNull_ = false;}
   else{periodMultiplierIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- periodMultiplierNode , address : " << periodMultiplierNode << std::endl;
   #endif
   if(periodMultiplierNode)
   {
      if(periodMultiplierNode->Attribute("href") || periodMultiplierNode->Attribute("id"))
      {
          if(periodMultiplierNode->Attribute("id"))
          {
             periodMultiplierIDRef_ = periodMultiplierNode->Attribute("id");
             periodMultiplier_ = boost::shared_ptr<XsdTypeInteger>(new XsdTypeInteger(periodMultiplierNode));
             periodMultiplier_->setID(periodMultiplierIDRef_);
             IDManager::instance().setID(periodMultiplierIDRef_,periodMultiplier_);
          }
          else if(periodMultiplierNode->Attribute("href")) { periodMultiplierIDRef_ = periodMultiplierNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { periodMultiplier_ = boost::shared_ptr<XsdTypeInteger>(new XsdTypeInteger(periodMultiplierNode));}
   }

   //periodNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* periodNode = xmlNode->FirstChildElement("period");

   if(periodNode){periodIsNull_ = false;}
   else{periodIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- periodNode , address : " << periodNode << std::endl;
   #endif
   if(periodNode)
   {
      if(periodNode->Attribute("href") || periodNode->Attribute("id"))
      {
          if(periodNode->Attribute("id"))
          {
             periodIDRef_ = periodNode->Attribute("id");
             period_ = boost::shared_ptr<PeriodEnum>(new PeriodEnum(periodNode));
             period_->setID(periodIDRef_);
             IDManager::instance().setID(periodIDRef_,period_);
          }
          else if(periodNode->Attribute("href")) { periodIDRef_ = periodNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { period_ = boost::shared_ptr<PeriodEnum>(new PeriodEnum(periodNode));}
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
boost::shared_ptr<XsdTypeInteger> Period::getPeriodMultiplier()
{
   if(!this->periodMultiplierIsNull_){
        if(periodMultiplierIDRef_ != ""){
             return boost::shared_static_cast<XsdTypeInteger>(IDManager::instance().getID(periodMultiplierIDRef_));
        }else{
             return this->periodMultiplier_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<XsdTypeInteger>();
   }
}
boost::shared_ptr<PeriodEnum> Period::getPeriod()
{
   if(!this->periodIsNull_){
        if(periodIDRef_ != ""){
             return boost::shared_static_cast<PeriodEnum>(IDManager::instance().getID(periodIDRef_));
        }else{
             return this->period_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<PeriodEnum>();
   }
}
}

