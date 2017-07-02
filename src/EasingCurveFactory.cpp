#include <memory>
#include <string>
#include "EasingCurveFactory.h"

using namespace std;

unique_ptr<EasingCurve> EasingCurveFactory::makeEasingCurve(const string& curveType){
	unique_ptr<EasingCurve> curve(nullptr);

	if(curveType=="Linear"){
      curve.reset(new EasingCurve("Linear"));
	  return curve;
	}

	return curve;
}
