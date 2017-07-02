#ifndef EASINGCURVE__H  
#define EASINGCURVE__H  

#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

class EasingCurve{
	public:
		EasingCurve();
		EasingCurve(const string curveType);
		virtual int evaluate(float time);
		virtual void readCurve(const string& line);

		string& getType();
	protected:
		string curveType;
		float x_t0;
		float x_tmax;
		float duration;

		unique_ptr<unordered_map<string,float>> getParametersFromLine(const string& line); 
		void setBasicParameters(const unique_ptr<unordered_map<string,float>>& parameters);
};

#endif  
