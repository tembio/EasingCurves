#ifndef INQUADCURVE__H  
#define INQUADCURVE__H  

#include <string>
#include "EasingCurve.h"

class InQuadCurve : public EasingCurve{
	public:
	  InQuadCurve();
	  void readCurve(const string& line);
 	  int evaluate(float time);
};

#endif  
