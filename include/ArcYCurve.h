#ifndef ARCYCURVE__H  
#define ARCYCURVE__H  

#include <string>
#include "ArcCurve.h"

class ArcYCurve : public ArcCurve{
	public:
	  ArcYCurve();
 	  int evaluate(float time);
};

#endif  
