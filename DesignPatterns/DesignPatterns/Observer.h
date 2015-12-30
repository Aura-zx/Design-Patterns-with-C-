#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
	Observer( );
	~Observer( );

	virtual void update(float temp, float humidity, float pressure) = 0;
private:

};

Observer::Observer( )
{
}

Observer::~Observer( )
{
}
#endif // !OBSERVER_H


