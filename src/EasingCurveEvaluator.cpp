#include "../include/EasingCurveEvaluator.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <memory>
#include <string>
#include <vector>

using namespace std;

bool isFloat(const string& s);
bool isCorrectParameter(const string& s);
bool containsChar(string s, char value);
string getEasingCurveName(const std::string &easingCurveLine);


EasingCurveEvaluator::EasingCurveEvaluator(unique_ptr<EasingCurveFactory> factory){
	this->factory = std::move(factory);
	this->currentEasingCurve = nullptr;
}

LineType EasingCurveEvaluator::getLineType(const string &line){

	if(isFloat(line))
		return TIME_VALUE;

	if(line=="" || !containsChar(line,',') || containsChar(line,' ')){
		return INVALID;
	}else{
	    vector<string> splitVec; 
	    boost::split(splitVec, line, boost::is_any_of(","));

	    if(containsChar(splitVec[0],'='))
		  return INVALID;

		for (auto begin = ++(splitVec.begin());begin != splitVec.end(); ++begin)  
			if(!isCorrectParameter(*begin))
				return INVALID;
	}

	return CURVE_DEFINITION;
}

bool EasingCurveEvaluator::processEasingCurve(const std::string &line){
    string name = getEasingCurveName(line);
    unique_ptr<EasingCurve> easingCurve = move(factory->makeEasingCurve(name));

	if(easingCurve == nullptr)
		return false;

	try{
		easingCurve->readCurve(line);
	}catch(...){
		return false;
	}

	currentEasingCurve = move(easingCurve);
	return true;
}

bool EasingCurveEvaluator::evaluateTime(const std::string &line, int &value){
	float t = boost::lexical_cast<float>(line);
	if(currentEasingCurve!=nullptr){
		value =  currentEasingCurve->evaluate(t);
		return true;
	}
	return false;
}


//Private methods

string getEasingCurveName(const std::string &easingCurve){
	vector<string> splitVec; 
	boost::split(splitVec, easingCurve, boost::is_any_of(","));
	return splitVec[0];
}

bool containsChar(string s, char value){
	return s.find(value) != std::string::npos;
}

bool isFloat(const string& s) { 
   bool isFloat = true; 
   try { 
      boost::lexical_cast<float>(s); 
   } 
   catch (boost::bad_lexical_cast &e) { 
      isFloat = false; 
   } 
   return isFloat; 
} 

bool isCorrectParameter(const string& param){
	vector<string> paramsParts; 
    boost::split(paramsParts, param, boost::is_any_of("="));

    if(paramsParts.size()!=2 || paramsParts[0]=="" || paramsParts[1]=="")
    	return false;

    try{
    	boost::lexical_cast<float>(paramsParts[1]);
    }catch(const boost::bad_lexical_cast &){
    	return false;
    }

	return true;
}
