// CalculationPeriodsReference.cpp 
#include "CalculationPeriodsReference.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

CalculationPeriodsReference::CalculationPeriodsReference(TiXmlNode* xmlNode)
: Reference(xmlNode)
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

