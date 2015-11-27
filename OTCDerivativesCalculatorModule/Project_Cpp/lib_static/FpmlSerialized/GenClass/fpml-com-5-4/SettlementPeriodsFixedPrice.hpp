// SettlementPeriodsFixedPrice.hpp 
#ifndef FpmlSerialized_SettlementPeriodsFixedPrice_hpp
#define FpmlSerialized_SettlementPeriodsFixedPrice_hpp

#include <fpml-com-5-4/FixedPrice.hpp>
#include <fpml-com-5-4/SettlementPeriodsReference.hpp>

namespace FpmlSerialized {

class SettlementPeriodsFixedPrice : public FixedPrice { 
   public: 
       SettlementPeriodsFixedPrice(TiXmlNode* xmlNode);

       bool isSettlementPeriodsReference(){return this->settlementPeriodsReferenceIsNull_;}
       std::vector<boost::shared_ptr<SettlementPeriodsReference>> getSettlementPeriodsReference();
      std::string getSettlementPeriodsReferenceIDRef(){return settlementPeriodsReferenceIDRef_;}

   protected: 
       std::vector<boost::shared_ptr<SettlementPeriodsReference>> settlementPeriodsReference_;
       std::string settlementPeriodsReferenceIDRef_;
       bool settlementPeriodsReferenceIsNull_;

};

} //namespaceFpmlSerialized end
#endif

