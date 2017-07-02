#include "ArcXCurve.h"
#include <math.h>

ArcXCurve::ArcXCurve(){
	this->curveType = "ArcX";
}

int ArcXCurve::evaluate(float t){
  return calculatePosition(t, [](float theta){return cos(theta);});	
}
