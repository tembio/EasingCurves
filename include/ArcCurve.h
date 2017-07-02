#ifndef ARCCURVE__H  
#define ARCCURVE__H  

#include <string>
#include "EasingCurve.h"

class ArcCurve : public EasingCurve{
	public:
	  void readCurve(const string& line);
 	  int evaluate(float time);
 	private:
 	  float radius;
 	  float theta_t0;
 	  float theta_tmax;
 	protected:
	  int calculatePosition(float t, std::function<float(float)> trigFunc);
};

#endif  
