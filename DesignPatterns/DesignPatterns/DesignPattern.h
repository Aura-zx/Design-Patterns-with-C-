#ifndef DESIGNPATTERNS_H
#define DESIGNPATTERNS_H

#include "SimUDuck.h"
class DesignPattern
{
public:
	DesignPattern( );
	~DesignPattern( );

	virtual void test( ) = 0;
private:

};

DesignPattern::DesignPattern( )
{
}

DesignPattern::~DesignPattern( )
{
}

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
#endif // !DESIGNPATTERNS_H
