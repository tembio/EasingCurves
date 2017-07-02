#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <memory>
#include <typeinfo>

#include "LinearCurve.h"
#include "EasingCurveFactory.h"
#include "EasingCurveEvaluator.h"

using namespace std;

TEST_CASE( "Easing curve", "[EasingCurve]" ) {

	SECTION( "is created with specified type" ) {
    	unique_ptr<EasingCurve> curve(new EasingCurve("Linear"));
    	REQUIRE( curve->getType() == "Linear" );
    }

}

TEST_CASE( "Linear curve", "[LinearCurve]" ) {
    unique_ptr<LinearCurve> curve(new LinearCurve());

	SECTION( "is created with Linear type" ) {
    	REQUIRE( curve->getType() == "Linear" );
    }

    SECTION( "throws exception if x_t0 parameter is missing" ) {
    	CHECK_THROWS(curve->readCurve("Linear,x_tmax=200,duration=1"));
    }

    SECTION( "throws exception if x_tmax parameter is missing" ) {
    	CHECK_THROWS(curve->readCurve("Linear,x_t0=100,duration=1"));
    }

    SECTION( "throws exception if duration parameter is missing" ) {
    	CHECK_THROWS(curve->readCurve("Linear,x_t0=100,x_tmax=200"));
    }
/*
    SECTION( "read parameter x_t0 from line" ) {
    	REQUIRE( curve->readCruve("Linear,x_t0=100,x_tmax=200,duration=1") == "Linear" );
    }*/
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
}

TEST_CASE( "Easing curve evaluator", "[EasingCurveEvaluator]" ) {

	unique_ptr<EasingCurveFactory> factory(new EasingCurveFactory());

	//GetLineType

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

    //SetEasingCurve

//	evaluator->setEasingCurve("Linear,x_t0=100,x_tmax=200,duration=1");
/*
    SECTION( "setEasingCurve sets easingCurve name to the curve read on the line" ) {
    	REQUIRE( evaluator->getEasingCurve().getType() == "Linear");
    }
*/
}