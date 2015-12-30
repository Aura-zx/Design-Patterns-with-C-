#ifndef DESIGNPATTERNS_H
#define DESIGNPATTERNS_H

#include "SimUDuck.h"
#include "H_Observer.h"
class DesignPattern
{
public:
	DesignPattern( );
	~DesignPattern( );

	virtual void test( ) = 0;
private:

};

DesignPattern::DesignPattern( )
{
}

DesignPattern::~DesignPattern( )
{
}

class Strategy :public DesignPattern
{
public:
	void test( )
	{
		RedDuck r1 = RedDuck( );
		r1.display( );
		r1.performFly( );
		r1.performQuack( );
		r1.setFlyBehavior(new FlyNoWays( ));
		r1.performFly( );
		r1.setQuackBehavior(new Squack( ));
		r1.performQuack( );
		r1.swim( );
	}
};

class Observer_d:public DesignPattern
{
public:
	void test( )
	{
		std::cout << "TEST 1 ......................................" << std::endl;
		WeatherData *weatherData = new WeatherData();
		CurrentConditionDisplay currentDisplay = CurrentConditionDisplay(weatherData);
		StatisticsDisplay statDisplay = StatisticsDisplay(weatherData);

		weatherData->setMeasurements(80.0, 65.0, 30.4);
		weatherData->setMeasurements(82.0, 70.0, 29.2);
	}

	void test2( )
	{
		std::cout << "TEST 2 ......................................" << std::endl;
		WeatherData *weatherData = new WeatherData( );
		CurrentConditionDisplay currentDisplay = CurrentConditionDisplay(weatherData);
		StatisticsDisplay statDisplay = StatisticsDisplay(weatherData);

		weatherData->setMeasurements(80.0, 65.0, 30.4);
		weatherData->setMeasurements(82.0, 70.0, 29.2);
		weatherData->removeObserver(&currentDisplay);
		weatherData->setMeasurements(100.0, 100.0, 100.0);
	}
};
#endif // !DESIGNPATTERNS_H
