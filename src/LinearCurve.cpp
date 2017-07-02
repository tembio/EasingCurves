#include "LinearCurve.h"
#include <unordered_map>
#include <memory>

LinearCurve::LinearCurve(){
	this->curveType = "Linear";
}

void LinearCurve::readCurve(const string& line){
   unique_ptr<unordered_map<string,float>> parameters;
   setBasicParameters(getParametersFromLine(line));
}

 int LinearCurve::evaluate(float t){
 	if(duration==0)
 		return x_t0;
 	return x_t0 + t*(x_tmax-x_t0)/duration;
 }
