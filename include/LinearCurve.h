#ifndef LINEARCURVE__H  
#define LINEARCURVE__H  

#include <string>
#include "EasingCurve.h"

class LinearCurve : public EasingCurve{
	public:
	  LinearCurve();
	  void readCurve(const string& line);
 	  int evaluate(float time);
};

#endif  
