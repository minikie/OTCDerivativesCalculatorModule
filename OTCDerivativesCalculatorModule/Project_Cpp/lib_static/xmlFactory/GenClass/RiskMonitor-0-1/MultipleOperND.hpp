// MultipleOperND.hpp 
#ifndef FpmlSerialized_MultipleOperND_hpp
#define FpmlSerialized_MultipleOperND_hpp

#include <ISerialized.hpp>
#include <built_in_type/XsdTypeToken.hpp>

namespace FpmlSerialized {

class MultipleOperND : public ISerialized { 
   public: 
       MultipleOperND(TiXmlNode* xmlNode);

       bool isWeight(){return this->weightIsNull_;}
       std::vector<boost::shared_ptr<XsdTypeToken>> getWeight();


   protected: 
       std::vector<boost::shared_ptr<XsdTypeToken>> weight_;
       
       bool weightIsNull_;

};

} //namespaceFpmlSerialized end
#endif

