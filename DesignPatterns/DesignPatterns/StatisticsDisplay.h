#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include "DisplayElement.h"
#include "Observer.h"
#include "WeatherData.h"

#include <iostream>
#include <string>
class StatisticsDisplay : public Observer, public DisplayElement
{
public:
	StatisticsDisplay( );
	StatisticsDisplay(Subject *weatherData);
	~StatisticsDisplay( );

	void update(float temp, float humidity, float pressure) 
	{
		this->temp = temp;
		this->humidity = humidity;
		this->pressure = pressure;
		display( );
	}

	void display( )
	{
		std::cout << "Statistics conditions: " + std::to_string(temp) + "F degrees " + std::to_string(humidity) + "% humidity and " \
					                           + std::to_string(pressure) + "Pa."<< std::endl;
	}
private:
	float temp;
	float humidity;
	float pressure;
	Subject *weatherData;

};

StatisticsDisplay::StatisticsDisplay() :temp(0.0), humidity(0.0), pressure(0.0), weatherData(nullptr)
{
}

StatisticsDisplay::StatisticsDisplay(Subject *weatherData)
{
	this->weatherData = weatherData;
	weatherData->registerObserver(this);
}

StatisticsDisplay::~StatisticsDisplay( )
{
}
#endif // !STATISTICSDISPLAY_H
