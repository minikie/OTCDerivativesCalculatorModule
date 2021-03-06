#include "IRStructuredDLS.hpp"
namespace QuantLib {

IRStructuredDLS::IRStructuredDLS(Natural settlementDays,
				  const Calendar& calendar,
				  const std::vector<boost::shared_ptr<Index>>& refIndex,
				  const boost::shared_ptr<PayoffLeg>& payoffLeg,
				  Real Notional,
				  const Date& issueDate
//				  const Leg& coupons
				  ) : refIndex_(refIndex),
				  Bond(settlementDays,calendar,issueDate,payoffLeg->leg()),
				  payoffLeg_(payoffLeg),Notional_(Notional)
{
	fixingDates_=payoffLeg->dates();
}

void IRStructuredDLS::setupArguments(PricingEngine::arguments* args) const
{
        IRStructuredDLS::arguments* arguments =
        dynamic_cast<IRStructuredDLS::arguments*>(args);
		

        QL_REQUIRE(arguments != 0, "wrong argument type");

		std::vector<Period> refIndexTenor;
		for(Size i=0;i<refIndex_.size();i++){
			//IndexMaturity.push_back(years(refIndex_[i]->tenor()));
			refIndexTenor.push_back(refIndex_[i]->tenor());
		}

		arguments->Notional         =   Notional_;
		arguments->settlementDate	=	settlementDate();
        arguments->cashflows		=	cashflows_;
        arguments->calendar			=	calendar_;
		arguments->refIndexTenor	=   refIndexTenor;
		arguments->fixingDates      =   fixingDates();
		arguments->payoffLeg        =	payoffLeg();

}
void IRStructuredDLS::fetchResults(const PricingEngine::results* r) const {

        Instrument::fetchResults(r);

        const IRStructuredDLS::results* results =
            dynamic_cast<const IRStructuredDLS::results*>(r);
        QL_ENSURE(results != 0, "wrong result type");

        settlementValue_ = results->settlementValue;
		Leg cashflows_=results->expectedCashflows;

}

Real IRStructuredDLS::accruedAmount(Date settlement) const{
	
	Real accrued=0.0;
	
	std::vector<boost::shared_ptr<MonteCoupon>> payoffs;

	payoffs=payoffLeg_->payoff();
	Size payoffNum=payoffs.size();

	for(Size i=0;payoffNum;++i){
		accrued+=payoffs[i]->accruedAmount(settlement);
	}

	return accrued;

	/*currentNotional = notional(settlementDate());
        if (currentNotional == 0.0)
            return 0.0;*/
}




}//nameSpace end