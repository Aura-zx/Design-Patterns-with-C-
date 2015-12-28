#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include <iostream>
class FlyBehavior
{
public:
	FlyBehavior( ) {};
	~FlyBehavior( ) {};
	virtual void fly( ) = 0;
private:

};

class FlyWithWings :public FlyBehavior
{
public:
	void fly( ) { std::cout << "I'm flying with wings." << std::endl; }
};

class FlyNoWays :public FlyBehavior
{
public:
	void fly( ) { std::cout << "I can't fly." << std::endl; }
};

#endif // !FLYBEHAVIOR_H
