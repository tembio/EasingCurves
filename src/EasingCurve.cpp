#include "../include/EasingCurve.h"
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

EasingCurve::EasingCurve(){}
EasingCurve::EasingCurve(const string curveType){
	this->curveType = curveType;
}
int EasingCurve::evaluate(float time){}
void EasingCurve::readCurve(const string& line){
  setBasicParameters(getParametersFromLine(line));	
}

string& EasingCurve::getType(){
	return curveType;
}

unique_ptr<unordered_map<string,float>> EasingCurve::getParametersFromLine(const string& line){
  unique_ptr<unordered_map<string,float>> parametersMap(new unordered_map<string,float>);
  vector<string> parameters; 

  boost::split(parameters, line, boost::is_any_of(","));
  parameters.erase(parameters.begin());

  for(string &parameter:parameters){
    vector<string> keyValuePair; 
    boost::split(keyValuePair, parameter, boost::is_any_of("="));
    (*parametersMap)[keyValuePair[0]] = boost::lexical_cast<float>(keyValuePair[1]);
  }

  return move(parametersMap);
}

void EasingCurve::setBasicParameters(const unique_ptr<unordered_map<string,float>>& parameters){
	if(parameters->find("x_t0") == parameters->end())
   	  throw "Parameter x_t0 missing!";
   
    if(parameters->find("x_tmax") == parameters->end())
   	  throw "Parameter x_tmax missing!";
   
    if(parameters->find("duration") == parameters->end())
   	  throw "Parameter duration missing!";

   	x_t0 = (*parameters)["x_t0"];
	x_tmax = (*parameters)["x_tmax"];
	duration = (*parameters)["duration"];
}
