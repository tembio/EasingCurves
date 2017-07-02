#ifndef INOUTQUADCURVE__H  
#define INOUTQUADCURVE__H  

#include <string>
#include "EasingCurve.h"

class InOutQuadCurve : public EasingCurve{
	public:
	  InOutQuadCurve();
	  void readCurve(const string& line);
 	  int evaluate(float time);
};

#endif  
