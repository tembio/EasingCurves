#include <iostream>
#include "EasingCurve.h"

class EasingCurveEvaluator{
	public:
		void evaluateLine(std::istream &stream);

	private:
		EasingCurve currentEasingCurve; 

		void readLine();
};