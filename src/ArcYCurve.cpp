#include "ArcYCurve.h"
#include <math.h>

ArcYCurve::ArcYCurve(){
	this->curveType = "ArcY";
}

int ArcYCurve::evaluate(float t){
  return calculatePosition(t, [](float theta){return sin(theta);});	
}
