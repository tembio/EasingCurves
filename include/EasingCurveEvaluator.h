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
		bool processEasingCurve(const std::string &line);
		bool evaluateTime(const std::string &line, int &value);

	private:
		unique_ptr<EasingCurveFactory> factory;
		unique_ptr<EasingCurve> currentEasingCurve; 

};
