#include <iostream>
#include <string>
#include "EasingCurveEvaluator.h"
#include "EasingCurveFactory.h"
#include <memory>

using namespace std;

int main(){

    unique_ptr<EasingCurveFactory> factory;
	EasingCurveEvaluator evaluator(move(factory));

	string lineBuffer;
	while (std::getline(cin, lineBuffer))
	{
		switch(evaluator.getLineType(lineBuffer)){
			case CURVE_DEFINITION:
				if(evaluator.processEasingCurve(lineBuffer))
				  cout<<lineBuffer<<endl;
				break;
			case TIME_VALUE:
				int value;
				if(evaluator.evaluateTime(lineBuffer,value))
			      cout<<value<<endl;
			    break;
		}
	}
}