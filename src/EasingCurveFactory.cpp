#include <memory>
#include <string>
#include "EasingCurveFactory.h"
#include "LinearCurve.h"

using namespace std;

unique_ptr<EasingCurve> EasingCurveFactory::makeEasingCurve(const string& curveType){
	unique_ptr<EasingCurve> curve(nullptr);

	if(curveType=="Linear"){
      curve.reset(new LinearCurve());
	}//else if(curveType=="InQuad"){
	 // curve.reset(new EasingCurve("InQuad"));
	//}

	return curve;
}
