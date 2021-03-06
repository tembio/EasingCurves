#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <memory>

#include "LinearCurve.h"
#include "InQuadCurve.h"
#include "OutQuadCurve.h"
#include "InOutQuadCurve.h"
#include "ArcYCurve.h"
#include "ArcXCurve.h"
#include "EasingCurveFactory.h"
#include "EasingCurveEvaluator.h"

using namespace std;

TEST_CASE( "Easing curve", "[EasingCurve]" ) {

	SECTION( "is created with specified type" ) {
    	unique_ptr<EasingCurve> curve(new EasingCurve("Linear"));
    	REQUIRE( curve->getType() == "Linear" );
    }

    SECTION( "throws exception if x_t0 parameter is missing" ) {
    	unique_ptr<EasingCurve> curve(new EasingCurve());
    	CHECK_THROWS(curve->readCurve("Linear,x_tmax=200,duration=1"));
    }

    SECTION( "throws exception if x_tmax parameter is missing" ) {
    	unique_ptr<EasingCurve> curve(new EasingCurve());
    	CHECK_THROWS(curve->readCurve("Linear,x_t0=100,duration=1"));
    }

    SECTION( "throws exception if duration parameter is missing" ) {
    	unique_ptr<EasingCurve> curve(new EasingCurve());
    	CHECK_THROWS(curve->readCurve("Linear,x_t0=100,x_tmax=200"));
    }
}

TEST_CASE( "Linear curve", "[LinearCurve]" ) {
    unique_ptr<LinearCurve> curve(new LinearCurve());

	SECTION( "is created with Linear type" ) {
    	REQUIRE( curve->getType() == "Linear" );
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("Linear,x_t0=100,x_tmax=200,duration=0");
    	REQUIRE( curve->evaluate(0.2) == 100 );
    }

    SECTION( "evaluates correctly the position for a given time " ) {
    	curve->readCurve("Linear,x_t0=100,x_tmax=200,duration=1");
    	REQUIRE( curve->evaluate(0.2) == 120 );
    }
}

TEST_CASE( "InQuad curve", "[InQuadCurve]" ) {
    unique_ptr<InQuadCurve> curve(new InQuadCurve());

	SECTION( "is created with InQuad type" ) {
    	REQUIRE( curve->getType() == "InQuad" );
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("InQuad,x_t0=100,x_tmax=200,duration=0");
    	REQUIRE( curve->evaluate(0.2) == 100 );
    }

    SECTION( "evaluates correctly the position time = 0 " ) {
    	curve->readCurve("InQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0) == 0 );
    }

    SECTION( "evaluates correctly the position time max " ) {
    	curve->readCurve("InQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(1) == 100 );
    }

    SECTION( "evaluates correctly the position for a given time " ) {
    	curve->readCurve("InQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0.5) == 25 );
    }
}


TEST_CASE( "OutQuad curve", "[OutQuadCurve]" ) {
    unique_ptr<OutQuadCurve> curve(new OutQuadCurve());

	SECTION( "is created with OutQuad type" ) {
    	REQUIRE( curve->getType() == "OutQuad" );
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("OutQuad,x_t0=100,x_tmax=200,duration=0");
    	REQUIRE( curve->evaluate(0.2) == 100 );
    }

    SECTION( "evaluates correctly the position time = 0 " ) {
    	curve->readCurve("OutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0) == 0 );
    }

    SECTION( "evaluates correctly the position time max " ) {
    	curve->readCurve("OutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(1) == 100 );
    }

    SECTION( "evaluates correctly the position for a given time " ) {
    	curve->readCurve("OutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0.5) == 75 );
    }
}

TEST_CASE( "InOutQuad curve", "[InOutQuadCurve]" ) {
    unique_ptr<InOutQuadCurve> curve(new InOutQuadCurve());

	SECTION( "is created with InOutQuad type" ) {
    	REQUIRE( curve->getType() == "InOutQuad" );
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("InOutQuad,x_t0=100,x_tmax=200,duration=0");
    	REQUIRE( curve->evaluate(0.2) == 100 );
    }

    SECTION( "evaluates correctly the position time = 0 " ) {
    	curve->readCurve("InOutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0) == 0 );
    }

    SECTION( "evaluates correctly the position time max " ) {
    	curve->readCurve("InOutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(1) == 100 );
    }

    SECTION( "evaluates correctly the position for a given time in first half " ) {
    	curve->readCurve("InOutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0.25) == 12 );
    }

	SECTION( "evaluates correctly the position for a given time in the middle point " ) {
    	curve->readCurve("InOutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0.5) == 50 );
    }

    SECTION( "evaluates correctly the position for a given time in second half " ) {
    	curve->readCurve("InOutQuad,x_t0=0,x_tmax=100,duration=1");
    	REQUIRE( curve->evaluate(0.75) == 87 );
    }
}

TEST_CASE( "ArcY curve", "[ArcYCurve]" ) {
    unique_ptr<ArcYCurve> curve(new ArcYCurve());

	SECTION( "is created with ArcY type" ) {
    	REQUIRE( curve->getType() == "ArcY" );
    }

    SECTION( "throws exception if radius parameter is missing" ) {
    	unique_ptr<ArcYCurve> curveCheckParam(new ArcYCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcY,x_t0=0,x_tmax=100,theta_t0=0,theta_tmax=3.14,duration=1"));
    }

    SECTION( "throws exception if theta_t0 parameter is missing" ) {
    	unique_ptr<ArcYCurve> curveCheckParam(new ArcYCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcY,x_t0=0,x_tmax=100,radius=1,theta_tmax=3.14,duration=1"));
    }

    SECTION( "throws exception if theta_tmax parameter is missing" ) {
    	unique_ptr<ArcYCurve> curveCheckParam(new ArcYCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcY,x_t0=0,x_tmax=100,radius=1,theta_t0=0,duration=1"));
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("ArcY,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.57,duration=1");
    	REQUIRE( curve->evaluate(0) == 0 );
    }

    SECTION( "evaluates correctly the position at time max" ) {
    	curve->readCurve("ArcY,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(1) == 100 );
    }

    SECTION( "evaluates correctly the position at the middle" ) {
    	curve->readCurve("ArcY,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(0.5) == 50 );
    }

    SECTION( "evaluates correctly the position for a given time" ) {
    	curve->readCurve("ArcY,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(0.75) == 75 );
    }
}

TEST_CASE( "ArcX curve", "[ArcXCurve]" ) {
    unique_ptr<ArcXCurve> curve(new ArcXCurve());

	SECTION( "is created with ArcX type" ) {
    	REQUIRE( curve->getType() == "ArcX" );
    }

    SECTION( "throws exception if radius parameter is missing" ) {
    	unique_ptr<ArcXCurve> curveCheckParam(new ArcXCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcX,x_t0=0,x_tmax=100,theta_t0=0,theta_tmax=3.14,duration=1"));
    }

    SECTION( "throws exception if theta_t0 parameter is missing" ) {
    	unique_ptr<ArcXCurve> curveCheckParam(new ArcXCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcX,x_t0=0,x_tmax=100,radius=1,theta_tmax=3.14,duration=1"));
    }

    SECTION( "throws exception if theta_tmax parameter is missing" ) {
    	unique_ptr<ArcXCurve> curveCheckParam(new ArcXCurve());
    	CHECK_THROWS(curveCheckParam->readCurve("ArcX,x_t0=0,x_tmax=100,radius=1,theta_t0=0,duration=1"));
    }

    SECTION( "returns initial position in evaluation when duration is 0" ) {
    	curve->readCurve("ArcX,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.57,duration=1");
    	REQUIRE( curve->evaluate(0) == 0 );
    }

    SECTION( "evaluates correctly the position at time max" ) {
    	curve->readCurve("ArcX,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(1) == -100 );
    }

    SECTION( "evaluates correctly the position at the middle" ) {
    	curve->readCurve("ArcX,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(0.5) == -50 );
    }

    SECTION( "evaluates correctly the position for a given time" ) {
    	curve->readCurve("ArcX,x_t0=0,x_tmax=100,radius=100,theta_t0=0,theta_tmax=1.5707963267,duration=1");
    	REQUIRE( curve->evaluate(0.75) == -75 );
    }
}

TEST_CASE( "Easing curve factory", "[EasingCurveFactory]" ) {
    unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());

    SECTION( "returns nullptr when no valid curve type is passed in" ) {
    	unique_ptr<EasingCurve> curve = factory->makeEasingCurve("InvalidCurveType");
    	REQUIRE(curve == nullptr);
    }

    SECTION( "returns EasingCurve when curve type is valid" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("Linear");
		REQUIRE(curve != nullptr);
    }

    SECTION( "returns LinearCurve when curve type Linear" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("Linear");
		REQUIRE(curve->getType() == "Linear");
    }

    SECTION( "returns InQuadCurve when curve type InQuad" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("InQuad");
		REQUIRE(curve->getType() == "InQuad");
    }

    SECTION( "returns OutQuadCurve when curve type OutQuad" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("OutQuad");
		REQUIRE(curve->getType() == "OutQuad");
    }

    SECTION( "returns InOutQuadCurve when curve type InOutQuad" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("InOutQuad");
		REQUIRE(curve->getType() == "InOutQuad");
    }

    SECTION( "returns ArcYCurve when curve type ArcY" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("ArcY");
		REQUIRE(curve->getType() == "ArcY");
    }

    SECTION( "returns ArcXCurve when curve type ArcX" ) {
		unique_ptr<EasingCurve> curve = factory->makeEasingCurve("ArcX");
		REQUIRE(curve->getType() == "ArcX");
    }
}

TEST_CASE( "Easing curve evaluator", "[EasingCurveEvaluator]" ) {

	unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());

	SECTION( "getLineType returns TIME_VALUE when the line has just one number" ) {
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));

    	REQUIRE( evaluator->getLineType("1.2") ==  TIME_VALUE);
    }

	SECTION( "getLineType returns INVALID type when receives empty lines" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("") ==  INVALID);
    }

    SECTION( "getLineType returns INVALID type when the line has white spaces" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("Linear, a=1") ==  INVALID);
    }

	SECTION( "getLineType returns INVALID when the line is not a number and there are no commas" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("hello123") ==  INVALID);
    }

	SECTION( "getLineType returns INVALID when the line is not a number and the first value is a parameter" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("hello=112,Linear") ==  INVALID);
    }

	SECTION( "getLineType returns INVALID when the parameters don't have the correct structure" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("Linear,=123") ==  INVALID);
    }

    SECTION( "getLineType returns INVALID when the parameters values are not floats" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("Linear,parameter=hello") ==  INVALID);
    }

    SECTION( "getLineType returns CURVE_DEFINITION when the line has curve name followed by well structured parameter" ) {
		unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());
    	unique_ptr<EasingCurveEvaluator> evaluator(new EasingCurveEvaluator(std::move(factory)));
    	REQUIRE( evaluator->getLineType("Linear,x_t0=100,x_tmax=200,duration=1") == CURVE_DEFINITION);
    }
}