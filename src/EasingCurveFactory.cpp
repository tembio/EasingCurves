#include <memory>
#include <string>
#include "EasingCurveFactory.h"
#include "LinearCurve.h"
#include "InQuadCurve.h"
#include "OutQuadCurve.h"
#include "InOutQuadCurve.h"
#include "ArcYCurve.h"
#include "ArcXCurve.h"

using namespace std;

unique_ptr<EasingCurve> EasingCurveFactory::makeEasingCurve(const string& curveType){
	unique_ptr<EasingCurve> curve(nullptr);

	if(curveType=="Linear")
      curve.reset(new LinearCurve());
	else if(curveType=="InQuad")
	  curve.reset(new InQuadCurve());
	else if(curveType=="OutQuad")
	  curve.reset(new OutQuadCurve());
	else if(curveType=="InOutQuad")
	  curve.reset(new InOutQuadCurve());
	else if(curveType=="ArcX")
	  curve.reset(new ArcXCurve());
	else if(curveType=="ArcY")
	  curve.reset(new ArcYCurve());
	
	return move(curve);
}
