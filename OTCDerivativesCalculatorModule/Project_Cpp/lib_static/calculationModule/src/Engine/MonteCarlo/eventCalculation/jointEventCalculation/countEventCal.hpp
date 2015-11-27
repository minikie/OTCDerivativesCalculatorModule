#ifndef quantlib_CountEventCal_hpp
#define quantlib_CountEventCal_hpp

#include <src/Engine/MonteCarlo/eventCalculation/jointEventCalculation/jointEventCalculation.hpp>

namespace QuantLib {

	class CountEventCal : public JointEventCalculation
	{
		public:
			CountEventCal(Size num,
						  const std::vector<boost::shared_ptr<EventCalculation>>& eventCalList,
						  const std::vector<boost::shared_ptr<VariableInfo>>& usingVariableInfoList = std::vector<boost::shared_ptr<VariableInfo>>() );

			void initializeImpl(const TimeGrid& timeGrid,
							const boost::shared_ptr<YieldTermStructure>& discountCurve,
							const boost::shared_ptr<PathGeneratorFactory>& pathGenFactory);
			
			bool checkEventImpl(const MultiPath& path,Size endPosition);

			//virtual bool pastEventOcc() = 0;
			//virtual std::vector<Date> fixingDates() const = 0;

	};
}

#endif