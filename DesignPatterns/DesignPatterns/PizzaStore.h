#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "Pizza.h"
#include <iostream>
#include <string>
class PizzaStore
{
public:
	PizzaStore( );
	~PizzaStore( );

	std::shared_ptr<Pizza> orderPizza(std::string type)
	{
		std::shared_ptr<Pizza> pizza = std::make_shared<Pizza>();
		pizza = createPizza(type);
		pizza->prepare( );
		pizza->bake( );
		pizza->cut( );
		pizza->box( );
		
		return pizza;
	}

	virtual std::shared_ptr<Pizza> createPizza(std::string type) = 0;

};

PizzaStore::PizzaStore( )
{
}

PizzaStore::~PizzaStore( )
{
}
#endif // !PIZZASTORE_H
