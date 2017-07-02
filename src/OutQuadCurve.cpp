#include "OutQuadCurve.h"
#include <unordered_map>
#include <memory>

OutQuadCurve::OutQuadCurve(){
	this->curveType = "OutQuad";
}

void OutQuadCurve::readCurve(const string& line){
   setBasicParameters(getParametersFromLine(line));
}

int OutQuadCurve::evaluate(float t){
 	if(duration==0)
 		return x_t0;
 	return x_t0 + (-t*(t-2))*(x_tmax-x_t0)/duration;
 }
