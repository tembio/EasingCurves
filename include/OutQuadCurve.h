#ifndef OUTQUADCURVE__H  
#define OUTQUADCURVE__H  

#include <string>
#include "EasingCurve.h"

class OutQuadCurve : public EasingCurve{
	public:
	  OutQuadCurve();
	  void readCurve(const string& line);
 	  int evaluate(float time);
};

#endif  
