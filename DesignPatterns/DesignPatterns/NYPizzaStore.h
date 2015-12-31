#ifndef NYSTYLEPIZZASTORE_H
#define NYSTYLEPIZZASTORE_H

#include "Pizza.h"
#include "PizzaStore.h"
#include "PizzaStyle.h"
#include <iostream>
#include <string>

class NYPizzaStore : public PizzaStore
{
public:
	NYPizzaStore( );
	~NYPizzaStore( );

	std::shared_ptr<Pizza> createPizza(std::string item)
	{
		if (item == "cheese")
		{
			std::shared_ptr<Pizza> p = std::make_shared<NYStyleChessPizza>( );
			return p;
		}
		else
		{
			std::shared_ptr<Pizza> p = std::make_shared<Pizza>( );
			return p;
		}
			
	}
private:

};

NYPizzaStore::NYPizzaStore( )
{
}

NYPizzaStore::~NYPizzaStore( )
{
}
#endif // !NYSTYLEPIZZASTORE_H
