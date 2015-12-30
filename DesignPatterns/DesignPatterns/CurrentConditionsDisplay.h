#ifndef CURRENTCONDITIONDISPLAY_H
#define CURRENTCONDITIONDISPLAY_H

#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>
class CurrentConditionDisplay : public Observer, public DisplayElement
{
public:
	CurrentConditionDisplay( );
	CurrentConditionDisplay(Subject *weatherData);
	~CurrentConditionDisplay( );

	void update(float temp, float humidity, float pressure);
	void display( );
private:
	float temp;
	float humidity;
	float pressure;
	Subject *weatherData;
};

CurrentConditionDisplay::CurrentConditionDisplay() :temp(0.0), humidity(0.0), pressure(0.0), weatherData(nullptr)
{
}

CurrentConditionDisplay::~CurrentConditionDisplay( )
{
}

CurrentConditionDisplay::CurrentConditionDisplay(Subject *weatherData) :temp(0.0), humidity(0.0), pressure(0.0)
{
	this->weatherData = weatherData;
	weatherData->registerObserver(this);
}

void CurrentConditionDisplay::update(float temp, float humidity, float pressure)
{
	this->temp = temp;
	this->humidity = humidity;
	display( );
}

void CurrentConditionDisplay::display( )
{
	std::cout << "Current conditions: " + std::to_string(temp) + "F degrees and " + std::to_string(humidity) + "% humidity" << std::endl;
}
#endif // !CURRENTCONDITIONDISPLAY_H
