#ifndef SIMUDUCK_H
#define SIMUDUCK_H

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
class Duck
{
public:
	Duck( ) {};
	~Duck( ) {};

	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;

	void swim( )	         { std::cout << "I'm swimming."<< std::endl; }
	void performFly( )       { flyBehavior->fly( ); }
	void performQuack( )     { quackBehavior->quack( ); }
	void setFlyBehavior(FlyBehavior *fb)   { flyBehavior = fb; }
	void setQuackBehavior(QuackBehavior *qb ) { quackBehavior = qb; }
	virtual void display( ) = 0;
private:

};

class RedDuck : public Duck
{
public:
	RedDuck( )
	{
		flyBehavior = new FlyWithWings( );
		quackBehavior = new Quack( );
    }
	void display( ) { std::cout << "I'm RedDuck." << std::endl; }
};
#endif // !SIMUDUCK_H
