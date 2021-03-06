//#include <src/Engine/MonteCarlo/StructuredProduct/IndexTran/IndexTransBase.hpp>
//
//namespace QuantLib {
//
//IndexTransBase::IndexTransBase()
//				: symbolName_("defualtSymbolName"), eqExpression_("defaultEqExpression") {}
//
//IndexTransBase::IndexTransBase(const std::string& symbolName,
//											 const std::string& eqExpression)
//				: symbolName_(symbolName), symbolValuesPtr_(IndexSymbolManager::instance().setSymbol(symbolName))
//{
//
//	parser_.DefineVar(symbolName,symbolValuesPtr_);
//	for(Size i=0;i<addedSymbols.size();++i){
//		this->defineVar(addedSymbols_[i]);
//	}
//	parser_.SetExpr(eqExpression_);
//	pastPosition_ = 0;
//
//}
//
//void IndexTransBase::initialize(const TimeGrid& timeGrid, const Calendar& calendar){
//	
//	Date today = Settings::instance().evaluationDate();
//	
//	//기준일이랑 얼마 지났는지니까.. 이건 템플릿으로 바꿔서 
//	//xml 파일로 세팅할때 픽스 시킬거임.
//	//가지고 있는 event가 daily check일 경우 생각. 2012-12-11
//	//pastPosition_ = calendar.businessDaysBetween(today,pastOservationDate_,true,false);
//
//	
//}
//
//std::vector<Size> IndexTransBase::averRelativeDatesPosition() const {
//	return averRelativeDatesPosition_;
//}
//
////void IndexTransManager::defineVar(const std::string varStr,double* value){
//void IndexTransBase::defineVar(const std::string varStr){
//	parser_.DefineVar(varStr,IndexSymbolManager::instance().setSymbol(varStr));
//}
//void IndexTransBase::defineConst(const std::string varStr,Real constValue){
//	parser_.DefineConst(varStr,constValue);
//}
//void IndexTransBase::defineBaseIndex(const std::string varStr){
//	parser_.DefineVar(varStr,IndexSymbolManager::instance().setSymbol(varStr));
//}
//
//// 나중에 이거때매 template로 가야하는 상황일 수도 있음 2012-11-28 (평균때매)
////template<class IndexCalType>
//void IndexTransBase::calValue(const MultiPath& multiPath,int refDatePosition){
//
//	indexPastFlag_=true;
//
//	//base는 딴데서 설정되어서 올거임.(eventcheck에서?)
//	//payoffDates_ = payoffDates_ - pastDays; 
//	//indexCalType_.calValue();
//
//	if(indexPastFlag_){
//		//multiPath_=&multiPath;
//		*symbolValuesPtr_ = parser_.Eval();
//	}else{
//		*symbolValuesPtr_ = multiPath[baseIndexNum_][refDatePosition - pastPosition_];
//	}
//}
//
////double IndexTransManager::pastUnder(int baseIndexNum , int pastDays){
////
////	//form 에서 조사해서 몇번째인지 넘길거임
////	return (*multiPath_)[baseIndexNum][payoffDatesPosition_ - pastDays];
////
////}
//std::vector<Date> IndexTransBase::averDates() const {
//	return averDates_;
//}
//
//bool IndexTransBase::average() const{
//	return averageFlag_;
//
//}
//
//std::string IndexTransBase::getSymbol(){
//	return symbolName_;
//}
//
//
//
//}