#ifndef DESIGNPATTERNS_H
#define DESIGNPATTERNS_H

#include "SimUDuck.h"
#include "H_Observer.h"
#include "Decorate.h"
#include "AbstractFactory.h"
class DesignPattern
{
public:
	DesignPattern( ) {}
	~DesignPattern() {}

	virtual void test( ) = 0;
private:

};

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

class Decorator : public DesignPattern
{
public:
	void test( )
	{
		std::cout << "Case 1 " << std::endl;
		std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>() ;
		std::cout << beverage->getDescription() + " $" + std::to_string(beverage->cost( )) << std::endl;

		std::cout << "Case 2 " << std::endl;
		std::shared_ptr<Beverage> beverage2 = std::make_shared<HouseBlend>( );
		beverage2 = std::make_shared<Mocha>(beverage2);
		beverage2 = std::make_shared<Mocha>(beverage2);
		beverage2 = std::make_shared<Whip>(beverage2);
		std::cout << beverage2->getDescription() + " $" + std::to_string(beverage2->cost( )) << std::endl;

		std::cout << "Case 3 " << std::endl;
		std::shared_ptr<Beverage> beverage3 = std::make_shared<HouseBlend>( );
		beverage3 = std::make_shared<Soy>(beverage3);
		beverage3 = std::make_shared<Mocha>(beverage3);
		beverage3 = std::make_shared<Whip>(beverage3);
		std::cout << beverage3->getDescription() + " $" + std::to_string(beverage3->cost( )) << std::endl;
	}
};

class AbstractFactory
{
public:
	void test( )
	{
		std::shared_ptr<PizzaStore> nyStore = std::make_shared<NYPizzaStore>();
		std::shared_ptr<PizzaStore> chicagoStore = std::make_shared<ChPizzaStore>( );

		std::shared_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
		std::cout << "You have a " + pizza->name << std::endl;

		pizza = chicagoStore->orderPizza("chicago");
		std::cout << "You have a " + pizza->name << std::endl;

	}
};
#endif // !DESIGNPATTERNS_H
