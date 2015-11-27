// BasketConstituent.cpp 
#include "BasketConstituent.hpp"
#ifdef ConsolePrint
    #include <iostream>
#endif 

namespace FpmlSerialized {

BasketConstituent::BasketConstituent(TiXmlNode* xmlNode)
: ISerialized(xmlNode)
{
    #ifdef ConsolePrint
        std::string initialtap_ = FileManager::instance().tap_;
        FileManager::instance().tap_.append("   ");
    #endif 
   //underlyingAssetNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* underlyingAssetNode = xmlNode->FirstChildElement("underlyingAsset");

   if(underlyingAssetNode){underlyingAssetIsNull_ = false;}
   else{underlyingAssetIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- underlyingAssetNode , address : " << underlyingAssetNode << std::endl;
   #endif
   if(underlyingAssetNode)
   {
      if(underlyingAssetNode->Attribute("href") || underlyingAssetNode->Attribute("id"))
      {
          if(underlyingAssetNode->Attribute("id"))
          {
             underlyingAssetIDRef_ = underlyingAssetNode->Attribute("id");
             underlyingAsset_ = boost::shared_ptr<Asset>(new Asset(underlyingAssetNode));
             underlyingAsset_->setID(underlyingAssetIDRef_);
             IDManager::instance().setID(underlyingAssetIDRef_,underlyingAsset_);
          }
          else if(underlyingAssetNode->Attribute("href")) { underlyingAssetIDRef_ = underlyingAssetNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { underlyingAsset_ = boost::shared_ptr<Asset>(new Asset(underlyingAssetNode));}
   }

   //basketNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* basketNode = xmlNode->FirstChildElement("basket");

   if(basketNode){basketIsNull_ = false;}
   else{basketIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- basketNode , address : " << basketNode << std::endl;
   #endif
   if(basketNode)
   {
      if(basketNode->Attribute("href") || basketNode->Attribute("id"))
      {
          if(basketNode->Attribute("id"))
          {
             basketIDRef_ = basketNode->Attribute("id");
             basket_ = boost::shared_ptr<Basket>(new Basket(basketNode));
             basket_->setID(basketIDRef_);
             IDManager::instance().setID(basketIDRef_,basket_);
          }
          else if(basketNode->Attribute("href")) { basketIDRef_ = basketNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { basket_ = boost::shared_ptr<Basket>(new Basket(basketNode));}
   }

   //bondNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* bondNode = xmlNode->FirstChildElement("bond");

   if(bondNode){bondIsNull_ = false;}
   else{bondIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- bondNode , address : " << bondNode << std::endl;
   #endif
   if(bondNode)
   {
      if(bondNode->Attribute("href") || bondNode->Attribute("id"))
      {
          if(bondNode->Attribute("id"))
          {
             bondIDRef_ = bondNode->Attribute("id");
             bond_ = boost::shared_ptr<Bond>(new Bond(bondNode));
             bond_->setID(bondIDRef_);
             IDManager::instance().setID(bondIDRef_,bond_);
          }
          else if(bondNode->Attribute("href")) { bondIDRef_ = bondNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { bond_ = boost::shared_ptr<Bond>(new Bond(bondNode));}
   }

   //cashNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* cashNode = xmlNode->FirstChildElement("cash");

   if(cashNode){cashIsNull_ = false;}
   else{cashIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- cashNode , address : " << cashNode << std::endl;
   #endif
   if(cashNode)
   {
      if(cashNode->Attribute("href") || cashNode->Attribute("id"))
      {
          if(cashNode->Attribute("id"))
          {
             cashIDRef_ = cashNode->Attribute("id");
             cash_ = boost::shared_ptr<Cash>(new Cash(cashNode));
             cash_->setID(cashIDRef_);
             IDManager::instance().setID(cashIDRef_,cash_);
          }
          else if(cashNode->Attribute("href")) { cashIDRef_ = cashNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { cash_ = boost::shared_ptr<Cash>(new Cash(cashNode));}
   }

   //commodityNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* commodityNode = xmlNode->FirstChildElement("commodity");

   if(commodityNode){commodityIsNull_ = false;}
   else{commodityIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- commodityNode , address : " << commodityNode << std::endl;
   #endif
   if(commodityNode)
   {
      if(commodityNode->Attribute("href") || commodityNode->Attribute("id"))
      {
          if(commodityNode->Attribute("id"))
          {
             commodityIDRef_ = commodityNode->Attribute("id");
             commodity_ = boost::shared_ptr<Commodity>(new Commodity(commodityNode));
             commodity_->setID(commodityIDRef_);
             IDManager::instance().setID(commodityIDRef_,commodity_);
          }
          else if(commodityNode->Attribute("href")) { commodityIDRef_ = commodityNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { commodity_ = boost::shared_ptr<Commodity>(new Commodity(commodityNode));}
   }

   //convertibleBondNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* convertibleBondNode = xmlNode->FirstChildElement("convertibleBond");

   if(convertibleBondNode){convertibleBondIsNull_ = false;}
   else{convertibleBondIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- convertibleBondNode , address : " << convertibleBondNode << std::endl;
   #endif
   if(convertibleBondNode)
   {
      if(convertibleBondNode->Attribute("href") || convertibleBondNode->Attribute("id"))
      {
          if(convertibleBondNode->Attribute("id"))
          {
             convertibleBondIDRef_ = convertibleBondNode->Attribute("id");
             convertibleBond_ = boost::shared_ptr<ConvertibleBond>(new ConvertibleBond(convertibleBondNode));
             convertibleBond_->setID(convertibleBondIDRef_);
             IDManager::instance().setID(convertibleBondIDRef_,convertibleBond_);
          }
          else if(convertibleBondNode->Attribute("href")) { convertibleBondIDRef_ = convertibleBondNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { convertibleBond_ = boost::shared_ptr<ConvertibleBond>(new ConvertibleBond(convertibleBondNode));}
   }

   //equityNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* equityNode = xmlNode->FirstChildElement("equity");

   if(equityNode){equityIsNull_ = false;}
   else{equityIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- equityNode , address : " << equityNode << std::endl;
   #endif
   if(equityNode)
   {
      if(equityNode->Attribute("href") || equityNode->Attribute("id"))
      {
          if(equityNode->Attribute("id"))
          {
             equityIDRef_ = equityNode->Attribute("id");
             equity_ = boost::shared_ptr<EquityAsset>(new EquityAsset(equityNode));
             equity_->setID(equityIDRef_);
             IDManager::instance().setID(equityIDRef_,equity_);
          }
          else if(equityNode->Attribute("href")) { equityIDRef_ = equityNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { equity_ = boost::shared_ptr<EquityAsset>(new EquityAsset(equityNode));}
   }

   //exchangeTradedFundNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* exchangeTradedFundNode = xmlNode->FirstChildElement("exchangeTradedFund");

   if(exchangeTradedFundNode){exchangeTradedFundIsNull_ = false;}
   else{exchangeTradedFundIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- exchangeTradedFundNode , address : " << exchangeTradedFundNode << std::endl;
   #endif
   if(exchangeTradedFundNode)
   {
      if(exchangeTradedFundNode->Attribute("href") || exchangeTradedFundNode->Attribute("id"))
      {
          if(exchangeTradedFundNode->Attribute("id"))
          {
             exchangeTradedFundIDRef_ = exchangeTradedFundNode->Attribute("id");
             exchangeTradedFund_ = boost::shared_ptr<ExchangeTradedFund>(new ExchangeTradedFund(exchangeTradedFundNode));
             exchangeTradedFund_->setID(exchangeTradedFundIDRef_);
             IDManager::instance().setID(exchangeTradedFundIDRef_,exchangeTradedFund_);
          }
          else if(exchangeTradedFundNode->Attribute("href")) { exchangeTradedFundIDRef_ = exchangeTradedFundNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { exchangeTradedFund_ = boost::shared_ptr<ExchangeTradedFund>(new ExchangeTradedFund(exchangeTradedFundNode));}
   }

   //futureNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* futureNode = xmlNode->FirstChildElement("future");

   if(futureNode){futureIsNull_ = false;}
   else{futureIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- futureNode , address : " << futureNode << std::endl;
   #endif
   if(futureNode)
   {
      if(futureNode->Attribute("href") || futureNode->Attribute("id"))
      {
          if(futureNode->Attribute("id"))
          {
             futureIDRef_ = futureNode->Attribute("id");
             future_ = boost::shared_ptr<Future>(new Future(futureNode));
             future_->setID(futureIDRef_);
             IDManager::instance().setID(futureIDRef_,future_);
          }
          else if(futureNode->Attribute("href")) { futureIDRef_ = futureNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { future_ = boost::shared_ptr<Future>(new Future(futureNode));}
   }

   //indexNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* indexNode = xmlNode->FirstChildElement("index");

   if(indexNode){indexIsNull_ = false;}
   else{indexIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- indexNode , address : " << indexNode << std::endl;
   #endif
   if(indexNode)
   {
      if(indexNode->Attribute("href") || indexNode->Attribute("id"))
      {
          if(indexNode->Attribute("id"))
          {
             indexIDRef_ = indexNode->Attribute("id");
             index_ = boost::shared_ptr<Index>(new Index(indexNode));
             index_->setID(indexIDRef_);
             IDManager::instance().setID(indexIDRef_,index_);
          }
          else if(indexNode->Attribute("href")) { indexIDRef_ = indexNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { index_ = boost::shared_ptr<Index>(new Index(indexNode));}
   }

   //loanNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* loanNode = xmlNode->FirstChildElement("loan");

   if(loanNode){loanIsNull_ = false;}
   else{loanIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- loanNode , address : " << loanNode << std::endl;
   #endif
   if(loanNode)
   {
      if(loanNode->Attribute("href") || loanNode->Attribute("id"))
      {
          if(loanNode->Attribute("id"))
          {
             loanIDRef_ = loanNode->Attribute("id");
             loan_ = boost::shared_ptr<Loan>(new Loan(loanNode));
             loan_->setID(loanIDRef_);
             IDManager::instance().setID(loanIDRef_,loan_);
          }
          else if(loanNode->Attribute("href")) { loanIDRef_ = loanNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { loan_ = boost::shared_ptr<Loan>(new Loan(loanNode));}
   }

   //mortgageNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* mortgageNode = xmlNode->FirstChildElement("mortgage");

   if(mortgageNode){mortgageIsNull_ = false;}
   else{mortgageIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- mortgageNode , address : " << mortgageNode << std::endl;
   #endif
   if(mortgageNode)
   {
      if(mortgageNode->Attribute("href") || mortgageNode->Attribute("id"))
      {
          if(mortgageNode->Attribute("id"))
          {
             mortgageIDRef_ = mortgageNode->Attribute("id");
             mortgage_ = boost::shared_ptr<Mortgage>(new Mortgage(mortgageNode));
             mortgage_->setID(mortgageIDRef_);
             IDManager::instance().setID(mortgageIDRef_,mortgage_);
          }
          else if(mortgageNode->Attribute("href")) { mortgageIDRef_ = mortgageNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { mortgage_ = boost::shared_ptr<Mortgage>(new Mortgage(mortgageNode));}
   }

   //mutualFundNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* mutualFundNode = xmlNode->FirstChildElement("mutualFund");

   if(mutualFundNode){mutualFundIsNull_ = false;}
   else{mutualFundIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- mutualFundNode , address : " << mutualFundNode << std::endl;
   #endif
   if(mutualFundNode)
   {
      if(mutualFundNode->Attribute("href") || mutualFundNode->Attribute("id"))
      {
          if(mutualFundNode->Attribute("id"))
          {
             mutualFundIDRef_ = mutualFundNode->Attribute("id");
             mutualFund_ = boost::shared_ptr<MutualFund>(new MutualFund(mutualFundNode));
             mutualFund_->setID(mutualFundIDRef_);
             IDManager::instance().setID(mutualFundIDRef_,mutualFund_);
          }
          else if(mutualFundNode->Attribute("href")) { mutualFundIDRef_ = mutualFundNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { mutualFund_ = boost::shared_ptr<MutualFund>(new MutualFund(mutualFundNode));}
   }

   //constituentWeightNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* constituentWeightNode = xmlNode->FirstChildElement("constituentWeight");

   if(constituentWeightNode){constituentWeightIsNull_ = false;}
   else{constituentWeightIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- constituentWeightNode , address : " << constituentWeightNode << std::endl;
   #endif
   if(constituentWeightNode)
   {
      if(constituentWeightNode->Attribute("href") || constituentWeightNode->Attribute("id"))
      {
          if(constituentWeightNode->Attribute("id"))
          {
             constituentWeightIDRef_ = constituentWeightNode->Attribute("id");
             constituentWeight_ = boost::shared_ptr<ConstituentWeight>(new ConstituentWeight(constituentWeightNode));
             constituentWeight_->setID(constituentWeightIDRef_);
             IDManager::instance().setID(constituentWeightIDRef_,constituentWeight_);
          }
          else if(constituentWeightNode->Attribute("href")) { constituentWeightIDRef_ = constituentWeightNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { constituentWeight_ = boost::shared_ptr<ConstituentWeight>(new ConstituentWeight(constituentWeightNode));}
   }

   //dividendPayoutNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* dividendPayoutNode = xmlNode->FirstChildElement("dividendPayout");

   if(dividendPayoutNode){dividendPayoutIsNull_ = false;}
   else{dividendPayoutIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- dividendPayoutNode , address : " << dividendPayoutNode << std::endl;
   #endif
   if(dividendPayoutNode)
   {
      if(dividendPayoutNode->Attribute("href") || dividendPayoutNode->Attribute("id"))
      {
          if(dividendPayoutNode->Attribute("id"))
          {
             dividendPayoutIDRef_ = dividendPayoutNode->Attribute("id");
             dividendPayout_ = boost::shared_ptr<DividendPayout>(new DividendPayout(dividendPayoutNode));
             dividendPayout_->setID(dividendPayoutIDRef_);
             IDManager::instance().setID(dividendPayoutIDRef_,dividendPayout_);
          }
          else if(dividendPayoutNode->Attribute("href")) { dividendPayoutIDRef_ = dividendPayoutNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { dividendPayout_ = boost::shared_ptr<DividendPayout>(new DividendPayout(dividendPayoutNode));}
   }

   //underlyerPriceNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* underlyerPriceNode = xmlNode->FirstChildElement("underlyerPrice");

   if(underlyerPriceNode){underlyerPriceIsNull_ = false;}
   else{underlyerPriceIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- underlyerPriceNode , address : " << underlyerPriceNode << std::endl;
   #endif
   if(underlyerPriceNode)
   {
      if(underlyerPriceNode->Attribute("href") || underlyerPriceNode->Attribute("id"))
      {
          if(underlyerPriceNode->Attribute("id"))
          {
             underlyerPriceIDRef_ = underlyerPriceNode->Attribute("id");
             underlyerPrice_ = boost::shared_ptr<Price>(new Price(underlyerPriceNode));
             underlyerPrice_->setID(underlyerPriceIDRef_);
             IDManager::instance().setID(underlyerPriceIDRef_,underlyerPrice_);
          }
          else if(underlyerPriceNode->Attribute("href")) { underlyerPriceIDRef_ = underlyerPriceNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { underlyerPrice_ = boost::shared_ptr<Price>(new Price(underlyerPriceNode));}
   }

   //underlyerNotionalNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* underlyerNotionalNode = xmlNode->FirstChildElement("underlyerNotional");

   if(underlyerNotionalNode){underlyerNotionalIsNull_ = false;}
   else{underlyerNotionalIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- underlyerNotionalNode , address : " << underlyerNotionalNode << std::endl;
   #endif
   if(underlyerNotionalNode)
   {
      if(underlyerNotionalNode->Attribute("href") || underlyerNotionalNode->Attribute("id"))
      {
          if(underlyerNotionalNode->Attribute("id"))
          {
             underlyerNotionalIDRef_ = underlyerNotionalNode->Attribute("id");
             underlyerNotional_ = boost::shared_ptr<Money>(new Money(underlyerNotionalNode));
             underlyerNotional_->setID(underlyerNotionalIDRef_);
             IDManager::instance().setID(underlyerNotionalIDRef_,underlyerNotional_);
          }
          else if(underlyerNotionalNode->Attribute("href")) { underlyerNotionalIDRef_ = underlyerNotionalNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { underlyerNotional_ = boost::shared_ptr<Money>(new Money(underlyerNotionalNode));}
   }

   //underlyerSpreadNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* underlyerSpreadNode = xmlNode->FirstChildElement("underlyerSpread");

   if(underlyerSpreadNode){underlyerSpreadIsNull_ = false;}
   else{underlyerSpreadIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- underlyerSpreadNode , address : " << underlyerSpreadNode << std::endl;
   #endif
   if(underlyerSpreadNode)
   {
      if(underlyerSpreadNode->Attribute("href") || underlyerSpreadNode->Attribute("id"))
      {
          if(underlyerSpreadNode->Attribute("id"))
          {
             underlyerSpreadIDRef_ = underlyerSpreadNode->Attribute("id");
             underlyerSpread_ = boost::shared_ptr<SpreadScheduleReference>(new SpreadScheduleReference(underlyerSpreadNode));
             underlyerSpread_->setID(underlyerSpreadIDRef_);
             IDManager::instance().setID(underlyerSpreadIDRef_,underlyerSpread_);
          }
          else if(underlyerSpreadNode->Attribute("href")) { underlyerSpreadIDRef_ = underlyerSpreadNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { underlyerSpread_ = boost::shared_ptr<SpreadScheduleReference>(new SpreadScheduleReference(underlyerSpreadNode));}
   }

   //couponPaymentNode ----------------------------------------------------------------------------------------------------------------------
   TiXmlElement* couponPaymentNode = xmlNode->FirstChildElement("couponPayment");

   if(couponPaymentNode){couponPaymentIsNull_ = false;}
   else{couponPaymentIsNull_ = true;}

   #ifdef ConsolePrint
      FileManager::instance().outFile_ << FileManager::instance().tap_.c_str() << "- couponPaymentNode , address : " << couponPaymentNode << std::endl;
   #endif
   if(couponPaymentNode)
   {
      if(couponPaymentNode->Attribute("href") || couponPaymentNode->Attribute("id"))
      {
          if(couponPaymentNode->Attribute("id"))
          {
             couponPaymentIDRef_ = couponPaymentNode->Attribute("id");
             couponPayment_ = boost::shared_ptr<PendingPayment>(new PendingPayment(couponPaymentNode));
             couponPayment_->setID(couponPaymentIDRef_);
             IDManager::instance().setID(couponPaymentIDRef_,couponPayment_);
          }
          else if(couponPaymentNode->Attribute("href")) { couponPaymentIDRef_ = couponPaymentNode->Attribute("href");}
          else { QL_FAIL("id or href error"); }
      }
      else { couponPayment_ = boost::shared_ptr<PendingPayment>(new PendingPayment(couponPaymentNode));}
   }

    #ifdef ConsolePrint
        FileManager::instance().tap_ = initialtap_;
    #endif 
}
boost::shared_ptr<Asset> BasketConstituent::getUnderlyingAsset()
{
   if(!this->underlyingAssetIsNull_){
        if(underlyingAssetIDRef_ != ""){
             return boost::shared_static_cast<Asset>(IDManager::instance().getID(underlyingAssetIDRef_));
        }else{
             return this->underlyingAsset_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Asset>();
   }
}
boost::shared_ptr<Basket> BasketConstituent::getBasket()
{
   if(!this->basketIsNull_){
        if(basketIDRef_ != ""){
             return boost::shared_static_cast<Basket>(IDManager::instance().getID(basketIDRef_));
        }else{
             return this->basket_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Basket>();
   }
}
boost::shared_ptr<Bond> BasketConstituent::getBond()
{
   if(!this->bondIsNull_){
        if(bondIDRef_ != ""){
             return boost::shared_static_cast<Bond>(IDManager::instance().getID(bondIDRef_));
        }else{
             return this->bond_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Bond>();
   }
}
boost::shared_ptr<Cash> BasketConstituent::getCash()
{
   if(!this->cashIsNull_){
        if(cashIDRef_ != ""){
             return boost::shared_static_cast<Cash>(IDManager::instance().getID(cashIDRef_));
        }else{
             return this->cash_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Cash>();
   }
}
boost::shared_ptr<Commodity> BasketConstituent::getCommodity()
{
   if(!this->commodityIsNull_){
        if(commodityIDRef_ != ""){
             return boost::shared_static_cast<Commodity>(IDManager::instance().getID(commodityIDRef_));
        }else{
             return this->commodity_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Commodity>();
   }
}
boost::shared_ptr<ConvertibleBond> BasketConstituent::getConvertibleBond()
{
   if(!this->convertibleBondIsNull_){
        if(convertibleBondIDRef_ != ""){
             return boost::shared_static_cast<ConvertibleBond>(IDManager::instance().getID(convertibleBondIDRef_));
        }else{
             return this->convertibleBond_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<ConvertibleBond>();
   }
}
boost::shared_ptr<EquityAsset> BasketConstituent::getEquity()
{
   if(!this->equityIsNull_){
        if(equityIDRef_ != ""){
             return boost::shared_static_cast<EquityAsset>(IDManager::instance().getID(equityIDRef_));
        }else{
             return this->equity_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<EquityAsset>();
   }
}
boost::shared_ptr<ExchangeTradedFund> BasketConstituent::getExchangeTradedFund()
{
   if(!this->exchangeTradedFundIsNull_){
        if(exchangeTradedFundIDRef_ != ""){
             return boost::shared_static_cast<ExchangeTradedFund>(IDManager::instance().getID(exchangeTradedFundIDRef_));
        }else{
             return this->exchangeTradedFund_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<ExchangeTradedFund>();
   }
}
boost::shared_ptr<Future> BasketConstituent::getFuture()
{
   if(!this->futureIsNull_){
        if(futureIDRef_ != ""){
             return boost::shared_static_cast<Future>(IDManager::instance().getID(futureIDRef_));
        }else{
             return this->future_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Future>();
   }
}
boost::shared_ptr<Index> BasketConstituent::getIndex()
{
   if(!this->indexIsNull_){
        if(indexIDRef_ != ""){
             return boost::shared_static_cast<Index>(IDManager::instance().getID(indexIDRef_));
        }else{
             return this->index_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Index>();
   }
}
boost::shared_ptr<Loan> BasketConstituent::getLoan()
{
   if(!this->loanIsNull_){
        if(loanIDRef_ != ""){
             return boost::shared_static_cast<Loan>(IDManager::instance().getID(loanIDRef_));
        }else{
             return this->loan_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Loan>();
   }
}
boost::shared_ptr<Mortgage> BasketConstituent::getMortgage()
{
   if(!this->mortgageIsNull_){
        if(mortgageIDRef_ != ""){
             return boost::shared_static_cast<Mortgage>(IDManager::instance().getID(mortgageIDRef_));
        }else{
             return this->mortgage_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Mortgage>();
   }
}
boost::shared_ptr<MutualFund> BasketConstituent::getMutualFund()
{
   if(!this->mutualFundIsNull_){
        if(mutualFundIDRef_ != ""){
             return boost::shared_static_cast<MutualFund>(IDManager::instance().getID(mutualFundIDRef_));
        }else{
             return this->mutualFund_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<MutualFund>();
   }
}
boost::shared_ptr<ConstituentWeight> BasketConstituent::getConstituentWeight()
{
   if(!this->constituentWeightIsNull_){
        if(constituentWeightIDRef_ != ""){
             return boost::shared_static_cast<ConstituentWeight>(IDManager::instance().getID(constituentWeightIDRef_));
        }else{
             return this->constituentWeight_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<ConstituentWeight>();
   }
}
boost::shared_ptr<DividendPayout> BasketConstituent::getDividendPayout()
{
   if(!this->dividendPayoutIsNull_){
        if(dividendPayoutIDRef_ != ""){
             return boost::shared_static_cast<DividendPayout>(IDManager::instance().getID(dividendPayoutIDRef_));
        }else{
             return this->dividendPayout_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<DividendPayout>();
   }
}
boost::shared_ptr<Price> BasketConstituent::getUnderlyerPrice()
{
   if(!this->underlyerPriceIsNull_){
        if(underlyerPriceIDRef_ != ""){
             return boost::shared_static_cast<Price>(IDManager::instance().getID(underlyerPriceIDRef_));
        }else{
             return this->underlyerPrice_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Price>();
   }
}
boost::shared_ptr<Money> BasketConstituent::getUnderlyerNotional()
{
   if(!this->underlyerNotionalIsNull_){
        if(underlyerNotionalIDRef_ != ""){
             return boost::shared_static_cast<Money>(IDManager::instance().getID(underlyerNotionalIDRef_));
        }else{
             return this->underlyerNotional_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<Money>();
   }
}
boost::shared_ptr<SpreadScheduleReference> BasketConstituent::getUnderlyerSpread()
{
   if(!this->underlyerSpreadIsNull_){
        if(underlyerSpreadIDRef_ != ""){
             return boost::shared_static_cast<SpreadScheduleReference>(IDManager::instance().getID(underlyerSpreadIDRef_));
        }else{
             return this->underlyerSpread_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<SpreadScheduleReference>();
   }
}
boost::shared_ptr<PendingPayment> BasketConstituent::getCouponPayment()
{
   if(!this->couponPaymentIsNull_){
        if(couponPaymentIDRef_ != ""){
             return boost::shared_static_cast<PendingPayment>(IDManager::instance().getID(couponPaymentIDRef_));
        }else{
             return this->couponPayment_;
        }
   }else
   {
      QL_FAIL("null Ptr");
      return boost::shared_ptr<PendingPayment>();
   }
}
}
