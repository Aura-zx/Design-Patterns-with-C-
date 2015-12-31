#ifndef PIZZASTYLE_H
#define PIZZASTYLE_H

#include "Pizza.h"

class NYStyleChessPizza : public Pizza
{
public:
	NYStyleChessPizza( );
	~NYStyleChessPizza( );

private:

};

NYStyleChessPizza::NYStyleChessPizza() 
{
	name = "NY Style Sauce and Cheese Pizza";
	dough = "Thin Crust Dough";
	sauce = "Marinara Sauce";

	toppings.push_back("Grated Reggiano Cheese");
}

NYStyleChessPizza::~NYStyleChessPizza( )
{
}

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza( );
	~ChicagoStyleCheesePizza( );
	
	void cut( )	{ std::cout << "Cutting the pizza into square slices" << std::endl;	}
};

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza( )
{
	name = "Chicago Style Deep Dish Cheese Pizza";
	dough = "Extra Thick Crust Dough";
	sauce = "Plum Tomato Sauce";

	toppings.push_back("Shredded Mozzarella Cheese");
}

ChicagoStyleCheesePizza::~ChicagoStyleCheesePizza( )
{
}
#endif // !NYSTYLECHESSPIZZA_H
