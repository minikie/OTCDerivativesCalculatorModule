// PersonRole.cpp 
#include "PersonRole.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

PersonRole::PersonRole(TiXmlNode* xmlNode)
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

