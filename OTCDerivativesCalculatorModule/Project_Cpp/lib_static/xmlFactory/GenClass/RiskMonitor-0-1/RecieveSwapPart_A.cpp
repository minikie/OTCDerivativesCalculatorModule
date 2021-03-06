// RecieveSwapPart_A.cpp 
#include "RecieveSwapPart_A.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

RecieveSwapPart_A::RecieveSwapPart_A(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //payoffInfoNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* payoffInfoNode = xmlNode->FirstChildElement("payoffInfo");

   if(payoffInfoNode){payoffInfoIsNull_ = false;}
   else{payoffInfoIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- payoffInfoNode , address : " << payoffInfoNode << std::endl;
   #endif
   if(payoffInfoNode)
   {
       payoffInfo_ = boost::shared_ptr<PayoffInfo>(new PayoffInfo(payoffInfoNode));
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
boost::shared_ptr<PayoffInfo> RecieveSwapPart_A::getPayoffInfo()
{
   if(!this->payoffInfoIsNull_){
        return this->payoffInfo_;
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<PayoffInfo>();
   }
}
}

