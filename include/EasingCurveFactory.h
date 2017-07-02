#ifndef EASINGCURVEFACTORY__H  
#define EASINGCURVEFACTORY__H  

#include <memory>
#include <string>
#include "EasingCurve.h"

using namespace std;

class EasingCurveFactory{
	public:
		unique_ptr<EasingCurve> makeEasingCurve(const string& curveType);
};

#endif  
