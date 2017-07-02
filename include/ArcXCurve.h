#ifndef ARCXCURVE__H  
#define ARCXCURVE__H  

#include <string>
#include "ArcCurve.h"

class ArcXCurve : public ArcCurve{
	public:
	  ArcXCurve();
 	  int evaluate(float time);
};

#endif  
