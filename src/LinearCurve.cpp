#include "LinearCurve.h"
#include <unordered_map>
#include <memory>

LinearCurve::LinearCurve(){
	this->curveType = "Linear";
}

void LinearCurve::readCurve(const string& line){
   unique_ptr<unordered_map<string,float>> parameters;
   parameters = getParametersFromLine(line);
   setBasicParameters(parameters);
}
