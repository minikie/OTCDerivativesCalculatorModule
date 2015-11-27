// InformationSource.hpp 
#ifndef FpmlSerialized_InformationSource_hpp
#define FpmlSerialized_InformationSource_hpp

#include <ISerialized.hpp>
#include <fpml-shared-5-4/InformationProvider.hpp>
#include <fpml-shared-5-4/RateSourcePage.hpp>
#include <built_in_type/XsdTypeString.hpp>

namespace FpmlSerialized {

class InformationSource : public ISerialized { 
   public: 
       InformationSource(TiXmlNode* xmlNode);

       bool isRateSource(){return this->rateSourceIsNull_;}
       boost::shared_ptr<InformationProvider> getRateSource();
      std::string getRateSourceIDRef(){return rateSourceIDRef_;}

       bool isRateSourcePage(){return this->rateSourcePageIsNull_;}
       boost::shared_ptr<RateSourcePage> getRateSourcePage();
      std::string getRateSourcePageIDRef(){return rateSourcePageIDRef_;}

       bool isRateSourcePageHeading(){return this->rateSourcePageHeadingIsNull_;}
       boost::shared_ptr<XsdTypeString> getRateSourcePageHeading();
      std::string getRateSourcePageHeadingIDRef(){return rateSourcePageHeadingIDRef_;}

   protected: 
       boost::shared_ptr<InformationProvider> rateSource_;
       std::string rateSourceIDRef_;
       bool rateSourceIsNull_;
       boost::shared_ptr<RateSourcePage> rateSourcePage_;
       std::string rateSourcePageIDRef_;
       bool rateSourcePageIsNull_;
       boost::shared_ptr<XsdTypeString> rateSourcePageHeading_;
       std::string rateSourcePageHeadingIDRef_;
       bool rateSourcePageHeadingIsNull_;

};

} //namespaceFpmlSerialized end
#endif

