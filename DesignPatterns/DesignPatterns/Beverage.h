#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage
{
public:
	Beverage( );
	~Beverage( );

	std::string getDescription( ) { return description; }
	virtual double cost( ) = 0;

private:
	std::string description;
};

Beverage::Beverage( ) :description(std::string())
{
}

Beverage::~Beverage( )
{
}

class Espresso : public Beverage
{
public:
	Espresso() :description("Espresso") { }

	double cost( ) { return 1.99; }
private:
	std::string description;
};

class HouseBlend : public Beverage
{
public:
	HouseBlend( ) :description("House Blend Coffee") { }

	double cost( ) { return 0.89; }
private:
	std::string description;
};
#endif // !BEVERAGE_H
