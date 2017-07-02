#include "ArcCurve.h"
#include <unordered_map>
#include <memory>

#include <iostream>

void ArcCurve::readCurve(const string& line){
   unique_ptr<unordered_map<string,float>> parameters;
   parameters = getParametersFromLine(line);
   setBasicParameters(parameters);

   if(parameters->find("radius") == parameters->end())
     throw "Parameter radius missing!";

   if(parameters->find("theta_t0") == parameters->end())
     throw "Parameter theta_t0 missing!";

   if(parameters->find("theta_tmax") == parameters->end())
     throw "Parameter theta_tmax missing!";

   radius = (*parameters)["radius"];
   theta_t0 = (*parameters)["theta_t0"];
   theta_tmax = (*parameters)["theta_tmax"];
}

int ArcCurve::evaluate(float t){}

int ArcCurve::calculatePosition(float t, std::function<float(float)> trigFunc){
    if(duration==0)
      return x_t0;

    float trig_t0 = trigFunc(theta_t0);
    float trig_tmax = trigFunc(theta_tmax);
    int position = x_t0 + (t*radius*(trig_tmax-trig_t0))/duration;

    return position;
} 
