// CommodityPhysicalQuantitySchedule.cpp 
#include "CommodityPhysicalQuantitySchedule.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

CommodityPhysicalQuantitySchedule::CommodityPhysicalQuantitySchedule(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //quantityStepNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* quantityStepNode = xmlNode->FirstChildElement("quantityStep");

   if(quantityStepNode){quantityStepIsNull_ = false;}
   else{quantityStepIsNull_ = true;}

   if(quantityStepNode)
   {
      for(quantityStepNode; quantityStepNode; quantityStepNode = quantityStepNode->NextSiblingElement("quantityStep")){
          #ifdef ConsolePrint
              FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- quantityStepNode , address : " << quantityStepNode << std::endl;
          #endif
          if(quantityStepNode->Attribute("href") || quantityStepNode->Attribute("id"))
          {
              if(quantityStepNode->Attribute("id"))
              {
                  quantityStepIDRef_ = quantityStepNode->Attribute("id");
                  quantityStep_.push_back(boost::shared_ptr<CommodityNotionalQuantity>(new CommodityNotionalQuantity(quantityStepNode)));
                  quantityStep_.back()->setID(quantityStepIDRef_);
                  IDManager::instance().setID(quantityStepIDRef_, quantityStep_.back());
              }
              else if(quantityStepNode->Attribute("href")) { quantityStepIDRef_ = quantityStepNode->Attribute("href");}
              else { QL_FAIL("id or href error"); }
          }
          else { quantityStep_.push_back(boost::shared_ptr<CommodityNotionalQuantity>(new CommodityNotionalQuantity(quantityStepNode)));}
      }
   }
   else {
       #ifdef ConsolePrint
           FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- quantityStepNode , address : " << quantityStepNode << std::endl;
       #endif
   }

   //deliveryPeriodsReferenceNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* deliveryPeriodsReferenceNode = xmlNode->FirstChildElement("deliveryPeriodsReference");

   if(deliveryPeriodsReferenceNode){deliveryPeriodsReferenceIsNull_ = false;}
   else{deliveryPeriodsReferenceIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- deliveryPeriodsReferenceNode , address : " << deliveryPeriodsReferenceNode << std::endl;
   #endif
   if(deliveryPeriodsReferenceNode)
   {
      if(deliveryPeriodsReferenceNode->Attribute("href") || deliveryPeriodsReferenceNode->Attribute("id"))
      {
          if(deliveryPeriodsReferenceNode->Attribute("id"))
          {
             deliveryPeriodsReferenceIDRef_ = deliveryPeriodsReferenceNode->Attribute("id");
             deliveryPeriodsReference_ = boost::shared_ptr<CalculationPeriodsReference>(new CalculationPeriodsReference(deliveryPeriodsReferenceNode));
             deliveryPeriodsReference_->setID(deliveryPeriodsReferenceIDRef_);
             IDManager::instance().setID(deliveryPeriodsReferenceIDRef_,deliveryPeriodsReference_);
          }
          else if(deliveryPeriodsReferenceNode->Attribute("href")) { deliveryPeriodsReferenceIDRef_ = deliveryPeriodsReferenceNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { deliveryPeriodsReference_ = boost::shared_ptr<CalculationPeriodsReference>(new CalculationPeriodsReference(deliveryPeriodsReferenceNode));}
   }

   //deliveryPeriodsScheduleReferenceNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* deliveryPeriodsScheduleReferenceNode = xmlNode->FirstChildElement("deliveryPeriodsScheduleReference");

   if(deliveryPeriodsScheduleReferenceNode){deliveryPeriodsScheduleReferenceIsNull_ = false;}
   else{deliveryPeriodsScheduleReferenceIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- deliveryPeriodsScheduleReferenceNode , address : " << deliveryPeriodsScheduleReferenceNode << std::endl;
   #endif
   if(deliveryPeriodsScheduleReferenceNode)
   {
      if(deliveryPeriodsScheduleReferenceNode->Attribute("href") || deliveryPeriodsScheduleReferenceNode->Attribute("id"))
      {
          if(deliveryPeriodsScheduleReferenceNode->Attribute("id"))
          {
             deliveryPeriodsScheduleReferenceIDRef_ = deliveryPeriodsScheduleReferenceNode->Attribute("id");
             deliveryPeriodsScheduleReference_ = boost::shared_ptr<CalculationPeriodsScheduleReference>(new CalculationPeriodsScheduleReference(deliveryPeriodsScheduleReferenceNode));
             deliveryPeriodsScheduleReference_->setID(deliveryPeriodsScheduleReferenceIDRef_);
             IDManager::instance().setID(deliveryPeriodsScheduleReferenceIDRef_,deliveryPeriodsScheduleReference_);
          }
          else if(deliveryPeriodsScheduleReferenceNode->Attribute("href")) { deliveryPeriodsScheduleReferenceIDRef_ = deliveryPeriodsScheduleReferenceNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { deliveryPeriodsScheduleReference_ = boost::shared_ptr<CalculationPeriodsScheduleReference>(new CalculationPeriodsScheduleReference(deliveryPeriodsScheduleReferenceNode));}
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
std::vector<boost::shared_ptr<CommodityNotionalQuantity>> CommodityPhysicalQuantitySchedule::getQuantityStep()
{
   if(!this->quantityStepIsNull_){
        if(quantityStepIDRef_ != ""){
             return this->quantityStep_;
        }else{
             return this->quantityStep_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return std::vector<boost::shared_ptr<CommodityNotionalQuantity>>();
   }
}
boost::shared_ptr<CalculationPeriodsReference> CommodityPhysicalQuantitySchedule::getDeliveryPeriodsReference()
{
   if(!this->deliveryPeriodsReferenceIsNull_){
        if(deliveryPeriodsReferenceIDRef_ != ""){
             return boost::shared_static_cast<CalculationPeriodsReference>(IDManager::instance().getID(deliveryPeriodsReferenceIDRef_));
        }else{
             return this->deliveryPeriodsReference_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<CalculationPeriodsReference>();
   }
}
boost::shared_ptr<CalculationPeriodsScheduleReference> CommodityPhysicalQuantitySchedule::getDeliveryPeriodsScheduleReference()
{
   if(!this->deliveryPeriodsScheduleReferenceIsNull_){
        if(deliveryPeriodsScheduleReferenceIDRef_ != ""){
             return boost::shared_static_cast<CalculationPeriodsScheduleReference>(IDManager::instance().getID(deliveryPeriodsScheduleReferenceIDRef_));
        }else{
             return this->deliveryPeriodsScheduleReference_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<CalculationPeriodsScheduleReference>();
   }
}
}

