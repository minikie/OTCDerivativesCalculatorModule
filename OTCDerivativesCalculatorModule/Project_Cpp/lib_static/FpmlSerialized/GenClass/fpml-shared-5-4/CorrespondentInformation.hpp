// CorrespondentInformation.hpp 
#ifndef FpmlSerialized_CorrespondentInformation_hpp
#define FpmlSerialized_CorrespondentInformation_hpp

#include <ISerialized.hpp>
#include <fpml-shared-5-4/RoutingIds.hpp>
#include <fpml-shared-5-4/RoutingExplicitDetails.hpp>
#include <fpml-shared-5-4/RoutingIdsAndExplicitDetails.hpp>
#include <fpml-shared-5-4/PartyReference.hpp>

namespace FpmlSerialized {

class CorrespondentInformation : public ISerialized { 
   public: 
       CorrespondentInformation(TiXmlNode* xmlNode);

       bool isRoutingIds(){return this->routingIdsIsNull_;}
       boost::shared_ptr<RoutingIds> getRoutingIds();
      std::string getRoutingIdsIDRef(){return routingIdsIDRef_;}

       bool isRoutingExplicitDetails(){return this->routingExplicitDetailsIsNull_;}
       boost::shared_ptr<RoutingExplicitDetails> getRoutingExplicitDetails();
      std::string getRoutingExplicitDetailsIDRef(){return routingExplicitDetailsIDRef_;}

       bool isRoutingIdsAndExplicitDetails(){return this->routingIdsAndExplicitDetailsIsNull_;}
       boost::shared_ptr<RoutingIdsAndExplicitDetails> getRoutingIdsAndExplicitDetails();
      std::string getRoutingIdsAndExplicitDetailsIDRef(){return routingIdsAndExplicitDetailsIDRef_;}

       bool isCorrespondentPartyReference(){return this->correspondentPartyReferenceIsNull_;}
       boost::shared_ptr<PartyReference> getCorrespondentPartyReference();
      std::string getCorrespondentPartyReferenceIDRef(){return correspondentPartyReferenceIDRef_;}

       std::string getChoiceStr_0(){
           std::string str;
           int count = 0;
           if(!routingIdsIsNull_){
                count += 1;
                str = "routingIds" ;
           }
           if(!routingExplicitDetailsIsNull_){
                count += 1;
                str = "routingExplicitDetails" ;
           }
           if(!routingIdsAndExplicitDetailsIsNull_){
                count += 1;
                str = "routingIdsAndExplicitDetails" ;
           }
           QL_REQUIRE(count == 1 , "too many choice" << count);
           choiceStr_0_ = str ;
           return choiceStr_0_;
       }
   protected: 
         boost::shared_ptr<RoutingIds> routingIds_;     //choice
       std::string routingIdsIDRef_;
       bool routingIdsIsNull_;
         boost::shared_ptr<RoutingExplicitDetails> routingExplicitDetails_;     //choice
       std::string routingExplicitDetailsIDRef_;
       bool routingExplicitDetailsIsNull_;
         boost::shared_ptr<RoutingIdsAndExplicitDetails> routingIdsAndExplicitDetails_;     //choice
       std::string routingIdsAndExplicitDetailsIDRef_;
       bool routingIdsAndExplicitDetailsIsNull_;
       boost::shared_ptr<PartyReference> correspondentPartyReference_;
       std::string correspondentPartyReferenceIDRef_;
       bool correspondentPartyReferenceIsNull_;

       //choiceStr 
       std::string choiceStr_0_;

};

} //namespaceFpmlSerialized end
#endif

