// MaximumOper1D.cpp 
#include "MaximumOper1D.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

MaximumOper1D::MaximumOper1D(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //constValueNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* constValueNode = xmlNode->FirstChildElement("constValue");

   if(constValueNode){constValueIsNull_ = false;}
   else{constValueIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- constValueNode , address : " << constValueNode << std::endl;
   #endif
   if(constValueNode)
   {
       constValue_ = boost::shared_ptr<XsdTypeToken>(new XsdTypeToken(constValueNode));
   }

   //refNameNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* refNameNode = xmlNode->FirstChildElement("refName");

   if(refNameNode){refNameIsNull_ = false;}
   else{refNameIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- refNameNode , address : " << refNameNode << std::endl;
   #endif
   if(refNameNode)
   {
       refName_ = boost::shared_ptr<XsdTypeToken>(new XsdTypeToken(refNameNode));
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
boost::shared_ptr<XsdTypeToken> MaximumOper1D::getConstValue()
{
   if(!this->constValueIsNull_){
        return this->constValue_;
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<XsdTypeToken>();
   }
}
boost::shared_ptr<XsdTypeToken> MaximumOper1D::getRefName()
{
   if(!this->refNameIsNull_){
        return this->refName_;
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<XsdTypeToken>();
   }
}
}
