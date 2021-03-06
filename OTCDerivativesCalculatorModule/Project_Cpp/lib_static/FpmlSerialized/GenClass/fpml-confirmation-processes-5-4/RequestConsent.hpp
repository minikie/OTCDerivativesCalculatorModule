// RequestConsent.hpp 
#ifndef FpmlSerialized_RequestConsent_hpp
#define FpmlSerialized_RequestConsent_hpp

#include <fpml-msg-5-4/CorrectableRequestMessage.hpp>
#include <fpml-shared-5-4/RequestedAction.hpp>
#include <fpml-msg-5-4/PortfolioReference.hpp>
#include <fpml-business-events-5-4/CompressionActivity.hpp>
#include <fpml-shared-5-4/OriginatingEvent.hpp>
#include <fpml-doc-5-4/Trade.hpp>
#include <fpml-business-events-5-4/TradeAmendmentContent.hpp>
#include <fpml-business-events-5-4/TradeNotionalChange.hpp>
#include <fpml-business-events-5-4/TerminatingEvent.hpp>
#include <fpml-business-events-5-4/TradeNovationContent.hpp>
#include <fpml-business-events-5-4/OptionExercise.hpp>
#include <fpml-business-events-5-4/OptionExpiry.hpp>
#include <fpml-business-events-5-4/DeClear.hpp>
#include <fpml-business-events-5-4/Withdrawal.hpp>
#include <fpml-business-events-5-4/AdditionalEvent.hpp>
#include <fpml-asset-5-4/BasicQuotation.hpp>
#include <fpml-shared-5-4/Party.hpp>
#include <fpml-shared-5-4/Account.hpp>

namespace FpmlSerialized {

class RequestConsent : public CorrectableRequestMessage { 
   public: 
       RequestConsent(TiXmlNode* xmlNode);

       bool isRequestedAction(){return this->requestedActionIsNull_;}
       boost::shared_ptr<RequestedAction> getRequestedAction();
      std::string getRequestedActionIDRef(){return requestedActionIDRef_;}

       bool isPortfolioReference(){return this->portfolioReferenceIsNull_;}
       boost::shared_ptr<PortfolioReference> getPortfolioReference();
      std::string getPortfolioReferenceIDRef(){return portfolioReferenceIDRef_;}

       bool isCompressionActivity(){return this->compressionActivityIsNull_;}
       boost::shared_ptr<CompressionActivity> getCompressionActivity();
      std::string getCompressionActivityIDRef(){return compressionActivityIDRef_;}

       bool isOriginatingEvent(){return this->originatingEventIsNull_;}
       boost::shared_ptr<OriginatingEvent> getOriginatingEvent();
      std::string getOriginatingEventIDRef(){return originatingEventIDRef_;}

       bool isTrade(){return this->tradeIsNull_;}
       boost::shared_ptr<Trade> getTrade();
      std::string getTradeIDRef(){return tradeIDRef_;}

       bool isAmendment(){return this->amendmentIsNull_;}
       boost::shared_ptr<TradeAmendmentContent> getAmendment();
      std::string getAmendmentIDRef(){return amendmentIDRef_;}

       bool isIncrease(){return this->increaseIsNull_;}
       boost::shared_ptr<TradeNotionalChange> getIncrease();
      std::string getIncreaseIDRef(){return increaseIDRef_;}

       bool isTerminatingEvent(){return this->terminatingEventIsNull_;}
       boost::shared_ptr<TerminatingEvent> getTerminatingEvent();
      std::string getTerminatingEventIDRef(){return terminatingEventIDRef_;}

       bool isTermination(){return this->terminationIsNull_;}
       boost::shared_ptr<TradeNotionalChange> getTermination();
      std::string getTerminationIDRef(){return terminationIDRef_;}

       bool isNovation(){return this->novationIsNull_;}
       boost::shared_ptr<TradeNovationContent> getNovation();
      std::string getNovationIDRef(){return novationIDRef_;}

       bool isOptionExercise(){return this->optionExerciseIsNull_;}
       boost::shared_ptr<OptionExercise> getOptionExercise();
      std::string getOptionExerciseIDRef(){return optionExerciseIDRef_;}

       bool isOptionExpiry(){return this->optionExpiryIsNull_;}
       std::vector<boost::shared_ptr<OptionExpiry>> getOptionExpiry();
      std::string getOptionExpiryIDRef(){return optionExpiryIDRef_;}

       bool isDeClear(){return this->deClearIsNull_;}
       boost::shared_ptr<DeClear> getDeClear();
      std::string getDeClearIDRef(){return deClearIDRef_;}

       bool isWithdrawal(){return this->withdrawalIsNull_;}
       boost::shared_ptr<Withdrawal> getWithdrawal();
      std::string getWithdrawalIDRef(){return withdrawalIDRef_;}

       bool isAdditionalEvent(){return this->additionalEventIsNull_;}
       boost::shared_ptr<AdditionalEvent> getAdditionalEvent();
      std::string getAdditionalEventIDRef(){return additionalEventIDRef_;}

       bool isQuote(){return this->quoteIsNull_;}
       std::vector<boost::shared_ptr<BasicQuotation>> getQuote();
      std::string getQuoteIDRef(){return quoteIDRef_;}

       bool isParty(){return this->partyIsNull_;}
       std::vector<boost::shared_ptr<Party>> getParty();
      std::string getPartyIDRef(){return partyIDRef_;}

       bool isAccount(){return this->accountIsNull_;}
       std::vector<boost::shared_ptr<Account>> getAccount();
      std::string getAccountIDRef(){return accountIDRef_;}

       std::string getChoiceStr_0(){
           std::string str;
           int count = 0;
           if(!originatingEventIsNull_){
                count += 1;
                str = "originatingEvent" ;
           }
           if(!tradeIsNull_){
                count += 1;
                str = "trade" ;
           }
           if(!amendmentIsNull_){
                count += 1;
                str = "amendment" ;
           }
           if(!increaseIsNull_){
                count += 1;
                str = "increase" ;
           }
           if(!terminatingEventIsNull_){
                count += 1;
                str = "terminatingEvent" ;
           }
           if(!terminationIsNull_){
                count += 1;
                str = "termination" ;
           }
           if(!novationIsNull_){
                count += 1;
                str = "novation" ;
           }
           if(!optionExerciseIsNull_){
                count += 1;
                str = "optionExercise" ;
           }
           if(!optionExpiryIsNull_){
                count += 1;
                str = "optionExpiry" ;
           }
           if(!deClearIsNull_){
                count += 1;
                str = "deClear" ;
           }
           if(!withdrawalIsNull_){
                count += 1;
                str = "withdrawal" ;
           }
           if(!additionalEventIsNull_){
                count += 1;
                str = "additionalEvent" ;
           }
           QL_REQUIRE(count == 1 , "too many choice" << count);
           choiceStr_0_ = str ;
           return choiceStr_0_;
       }
   protected: 
       boost::shared_ptr<RequestedAction> requestedAction_;
       std::string requestedActionIDRef_;
       bool requestedActionIsNull_;
       boost::shared_ptr<PortfolioReference> portfolioReference_;
       std::string portfolioReferenceIDRef_;
       bool portfolioReferenceIsNull_;
       boost::shared_ptr<CompressionActivity> compressionActivity_;
       std::string compressionActivityIDRef_;
       bool compressionActivityIsNull_;
         boost::shared_ptr<OriginatingEvent> originatingEvent_;     //choice
       std::string originatingEventIDRef_;
       bool originatingEventIsNull_;
         boost::shared_ptr<Trade> trade_;     //choice
       std::string tradeIDRef_;
       bool tradeIsNull_;
         boost::shared_ptr<TradeAmendmentContent> amendment_;     //choice
       std::string amendmentIDRef_;
       bool amendmentIsNull_;
         boost::shared_ptr<TradeNotionalChange> increase_;     //choice
       std::string increaseIDRef_;
       bool increaseIsNull_;
         boost::shared_ptr<TerminatingEvent> terminatingEvent_;     //choice
       std::string terminatingEventIDRef_;
       bool terminatingEventIsNull_;
         boost::shared_ptr<TradeNotionalChange> termination_;     //choice
       std::string terminationIDRef_;
       bool terminationIsNull_;
         boost::shared_ptr<TradeNovationContent> novation_;     //choice
       std::string novationIDRef_;
       bool novationIsNull_;
         boost::shared_ptr<OptionExercise> optionExercise_;     //choice
       std::string optionExerciseIDRef_;
       bool optionExerciseIsNull_;
         std::vector<boost::shared_ptr<OptionExpiry>> optionExpiry_;     //choice
       std::string optionExpiryIDRef_;
       bool optionExpiryIsNull_;
         boost::shared_ptr<DeClear> deClear_;     //choice
       std::string deClearIDRef_;
       bool deClearIsNull_;
         boost::shared_ptr<Withdrawal> withdrawal_;     //choice
       std::string withdrawalIDRef_;
       bool withdrawalIsNull_;
         boost::shared_ptr<AdditionalEvent> additionalEvent_;     //choice
       std::string additionalEventIDRef_;
       bool additionalEventIsNull_;
       std::vector<boost::shared_ptr<BasicQuotation>> quote_;
       std::string quoteIDRef_;
       bool quoteIsNull_;
       std::vector<boost::shared_ptr<Party>> party_;
       std::string partyIDRef_;
       bool partyIsNull_;
       std::vector<boost::shared_ptr<Account>> account_;
       std::string accountIDRef_;
       bool accountIsNull_;

       //choiceStr 
       std::string choiceStr_0_;

};

} //namespaceFpmlSerialized end
#endif

