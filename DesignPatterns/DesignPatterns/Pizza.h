#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>

class Pizza
{
public:
	Pizza( ): name("Pure Pizza"), dough(""), sauce("") { } 
	~Pizza( ) {}

	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;

	void prepare( );
	void bake( ) { std::cout << "Bake for 25 min at 350." << std::endl; }
	void cut( ) { std::cout << "Cutting pizza into diagonal slices." << std::endl; }
	void box( ) { std::cout << "Place pizza into official box." << std::endl; }

};

void Pizza::prepare( )
{
	std::cout << "Prepareing " + name << std::endl;
	std::cout << "Tosssing dough..." << std::endl;
	std::cout << "Adding sauce..." << std::endl;
	std::cout << "Adding toppings: " << std::endl;

	for (auto &i : toppings)
	{
		std::cout << i << std::endl;
	}
}

#endif // !PIZZA_H
