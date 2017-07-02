#include "InOutQuadCurve.h"
#include <unordered_map>
#include <memory>

InOutQuadCurve::InOutQuadCurve(){
	this->curveType = "InOutQuad";
}

void InOutQuadCurve::readCurve(const string& line){
   unique_ptr<unordered_map<string,float>> parameters;
   setBasicParameters(getParametersFromLine(line));
}

int InOutQuadCurve::evaluate(float t){
 	if(duration==0)
 		return x_t0;

 	float middlePoint = duration/2.;

 	if(t<=middlePoint){
	 	return x_t0 + 2*t*t*(x_tmax-x_t0)/duration;
 	}else{
	 	return x_t0 + (-1+(4-2*t)*t)*(x_tmax-x_t0)/duration;
 	}
 }
