#include "ComplexTimeVariableValue.hpp"
#include <calculationModule/src/Engine/MonteCarlo/StructuredProduct/symbolmanager/IndexSymbolManager.hpp>
#include <calculationModule/src/Engine/MonteCarlo/StructuredProduct/symbolmanager/pathInformation.hpp>

namespace QuantLib {

ComplexTimeVariableValue::ComplexTimeVariableValue(const std::string& symbolName)
: VariableValue()
{
	this->symbolName_ = symbolName;
	//IndexSymbolManager::instance().setVariableValue(symbolName,this);
	this->variableBindingFlag_ = false;
}

ComplexTimeVariableValue::ComplexTimeVariableValue(const boost::shared_ptr<IndexTransBase>& itb,
	  											 const std::string& symbolName,
												 const std::vector<boost::shared_ptr<VariableValue>>& addedVariableValues)
: VariableValue(), itb_(itb), addedVariableValues_(addedVariableValues)
{
	this->symbolName_ = symbolName;
	this->setSymbolManagerFlag_ = true;
	this->variableBindingFlag_ = true;

	for(Size i = 0 ; i < addedVariableValues_.size() ; ++i)
	{
		bool tf = addedVariableValues_[i]->variableBindingFlag();
		if(!tf)
		{
			this->variableBindingFlag_ = false;
			break;
		}
	}
}

void ComplexTimeVariableValue::registManager()
{
	if(this->setSymbolManagerFlag_)
		IndexSymbolManager::instance().setSymbol(symbolName_,shared_from_this());
}

//void ComplexTimeVariableValue::addVariableValue(const boost::shared_ptr<VariableValue>& variableValue)
//{
//	this->addedVariableValues_.push_back(variableValue);
//}
void ComplexTimeVariableValue::initialize(const std::vector<Date>& eventDates)
{
	eventDates_ = eventDates;

	for(Size i = 0 ; i < addedVariableValues_.size() ; ++i)
	{
		addedVariableValues_[i]->initialize(eventDates);
	}	
}

void ComplexTimeVariableValue::variableBind(const std::vector<std::string>& circulationCheckString)
{
	std::vector<std::string> newCirculationCheckString = circulationCheckString;

	for(Size i = 0 ; i < circulationCheckString.size() ; ++i)
	{
		if(circulationCheckString[i] == this->symbolName_)
			QL_FAIL("circulation Symbol dectected. circulated symbolName : " << this->symbolName_ );
	}

	newCirculationCheckString.push_back(this->symbolName_);

	if(!(this->variableBindingFlag_))
	{
		for(Size i = 0 ; i < addedVariableValues_.size() ; ++i)
		{
			const std::string& symbolName = addedVariableValues_[i]->symbolName();

			if(symbolName != "No_Symbol"){
				addedVariableValues_[i] = IndexSymbolManager::instance().getSymbol(symbolName,newCirculationCheckString);
			}
		}	

		this->variableBindingFlag_ = true;
	}
	
	this->itb_->variableBind();
}

void ComplexTimeVariableValue::variablePtrBind()
{
	if(!this->ptrBindingFlag_)
	{
		value_ = 0.0;
		this->valuePtr_ = &(this->value_);

		for(Size i = 0 ; i < addedVariableValues_.size() ; ++i)
		{
			addedVariableValues_[i]->variablePtrBind();
		}

		this->ptrBindingFlag_ = true;
	}

	itb_->variablePtrBind();
}

void ComplexTimeVariableValue::calculate(Size timePosition)
{

	for(Size i=0 ; i<addedVariableValues_.size() ; ++i)
	{
		addedVariableValues_[i]->calculate(timePosition);
	}

	this->itb_->calculate();
}

//time���� ���������� ��� �Ͽ� eventdates Maximum ������ ���ߴ볪..? 2013-02-25
//time�ΰ�� �Ǿտ����� �˻��ϰ� simple�ΰ�� ���������� �˻���.
void ComplexTimeVariableValue::validFixingDates(const std::vector<Date>& eventDates)
{
	const Date& eventDateFront = eventDates.front();

	bool eventDateCheckFlag = false;
	bool eventDateFrontCheckFlag = false;

	//eventDate �� ������ �˻�.
	for(Size i=0;i<addedVariableValues_.size();++i)
	{
		const std::vector<Date>& dates = addedVariableValues_[i]->eventDates();
		const Date& roopDate = addedVariableValues_[i]->calculateLastIndexFixing();

		if(eventDates.size() == dates.size() 
			&& eventDates.front() == dates.front() 
				&& eventDates.back() == dates.back() 
					&& eventDates.size() > 1)
		{
			eventDateCheckFlag = true;
		}
		
		if(  roopDate < eventDateFront )
		{
			eventDateFrontCheckFlag = true;
		}
	}
	//if()
	QL_REQUIRE(eventDateCheckFlag == true || eventDateFrontCheckFlag == true, "validFixingDates error");

}

Date ComplexTimeVariableValue::calculateLastIndexFixing()
{
	if(!(this->variableBindingFlag_))
		QL_FAIL("variable is not bind");
		
	for(Size i=0;i<addedVariableValues_.size();++i)
	{
		const Date& roopDate = addedVariableValues_[i]->calculateLastIndexFixing();

		if( lastFixingDate_ < roopDate )
		{
			lastFixingDate_ = roopDate;
		}
	}

	return lastFixingDate_;
	
}

std::vector<Date> ComplexTimeVariableValue::indexFixingDates()
{
	if(!variableBindingFlag_)
		QL_FAIL("variable is not binding");

	std::vector<Date> dates;

	for(Size i = 0 ; i < this->addedVariableValues_.size() ; ++i)
	{
		const std::vector<Date>& fixings = this->addedVariableValues_[i]->indexFixingDates();
		dates.insert( dates.begin() , fixings.begin(),fixings.end() );
	}

	return dates;
}


}