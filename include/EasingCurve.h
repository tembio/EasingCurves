#include <string>

class EasingCurve{
	public:
		virtual int evaluate(float time);
		virtual void readCurve();
	protected:
		std::string name;
		int x_t0;
		int x_tmax;
		float duration; 
};