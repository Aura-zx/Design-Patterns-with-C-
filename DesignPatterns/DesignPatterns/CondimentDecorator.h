#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "Beverage.h"

#include <iostream>
#include <memory>
#include <string>
class CondimentDecorator : public  Beverage
{
public:
	CondimentDecorator( ) {}
	~CondimentDecorator( ) {}

	virtual std::string getDescription( ) = 0;
private:


};

class Mocha : public CondimentDecorator
{
public:
	std::shared_ptr<Beverage> beverage;
	Mocha(std::shared_ptr<Beverage> beverage) { this->beverage = beverage; }
	std::string getDescription( )	          {	return beverage->getDescription() + ", Mocha";}
	double cost( )							  { return 0.20 + beverage->cost( ); }
};

class Soy : public CondimentDecorator
{
public:
	std::shared_ptr<Beverage> beverage;
	Soy(std::shared_ptr<Beverage> beverage)   { this->beverage = beverage; }
	std::string getDescription( )	          { return beverage->getDescription() + ", Soy"; }
	double cost( )							  { return 0.30 + beverage->cost( ); }
};

class Whip : public CondimentDecorator
{
public:
	std::shared_ptr<Beverage> beverage;
	Whip(std::shared_ptr<Beverage> beverage)   { this->beverage = beverage; }
	std::string getDescription( )	          { return beverage->getDescription() + ", Whip"; }
	double cost( )							  { return 0.40 + beverage->cost( ); }
};
#endif // !CONDIMENTDECORATOR_H
