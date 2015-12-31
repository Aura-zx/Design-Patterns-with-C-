#ifndef CHPIZZASTORE_H
#define CHPIZZASTORE_H

#include "Pizza.h"
#include "PizzaStore.h"
#include "PizzaStyle.h"
#include <iostream>
#include <string>

class ChPizzaStore : public PizzaStore
{
public:
	ChPizzaStore( ) {}
	~ChPizzaStore( ) {}

	std::shared_ptr<Pizza>  createPizza(std::string item)
	{
		if (item == "chicago")
		{
			std::shared_ptr<Pizza> chi = std::make_shared<ChicagoStyleCheesePizza>();
			return chi;
		}
		else
		{
			std::shared_ptr<Pizza> p = std::make_shared<Pizza>( );
			return p;
		}

	}
};
#endif // !CHPIZZASTORE_H
