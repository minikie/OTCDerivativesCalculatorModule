// SpreadScheduleType.cpp 
#include "SpreadScheduleType.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

SpreadScheduleType::SpreadScheduleType(TiXmlNode* xmlNode)
: Scheme(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
}

