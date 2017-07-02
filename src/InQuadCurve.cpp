#include "InQuadCurve.h"
#include <unordered_map>
#include <memory>

InQuadCurve::InQuadCurve(){
	this->curveType = "InQuad";
}

void InQuadCurve::readCurve(const string& line){
   setBasicParameters(getParametersFromLine(line));
}

int InQuadCurve::evaluate(float t){
 	if(duration==0)
 		return x_t0;
 	return x_t0 + (t*t)*(x_tmax-x_t0)/duration;
 }
