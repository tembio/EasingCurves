#include <iostream>
#include <memory>
#include "EasingCurve.h"
#include "EasingCurveFactory.h"
#include <string>

enum LineType{ CURVE_DEFINITION, TIME_VALUE, INVALID };

class EasingCurveEvaluator{
	public:
		EasingCurveEvaluator(unique_ptr<EasingCurveFactory> factory);
		LineType getLineType(const std::string &line);
		void setEasingCurve(const std::string &line);
		EasingCurve& getEasingCurve();
		int evaluateTime(float timeValue);

	private:
		unique_ptr<EasingCurveFactory> factory;
		EasingCurve currentEasingCurve; 

};
