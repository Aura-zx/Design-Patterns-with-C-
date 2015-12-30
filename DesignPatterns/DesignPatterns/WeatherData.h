#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Subject.h"
#include "Observer.h"
#include <algorithm>
#include <vector>

class WeatherData : public Subject
{
public:
	WeatherData( );
	~WeatherData( );

	void registerObserver(Observer *ob);
	void removeObserver(Observer *ob);
	void notifyObserver( );
	void measurementsChanged( );
	void setMeasurements(float temp, float humidity, float pressure);

private:
	std::vector<Observer*> v_ob;
	float temp;
	float humidity;
	float pressure;
};

WeatherData::WeatherData() :temp(0.0), humidity(0.0), pressure(0.0)
{
	v_ob = std::vector<Observer*>( );
}

WeatherData::~WeatherData( )
{
}

void WeatherData::registerObserver(Observer *ob)
{
	v_ob.push_back(ob);
}

void WeatherData::removeObserver(Observer *ob)
{
	auto p = std::find(v_ob.begin(), v_ob.end(), ob);
	v_ob.erase(p);
}

void WeatherData::notifyObserver( )
{
	// 1. range-based loop
	for (auto &i : v_ob) {i->update(temp, humidity, pressure);}

	// 2. for_each + lambda
	//std::for_each(v_ob.begin( ), v_ob.end( ), [&](typename std::vector<Observer*>::value_type i) { i->update(temp, humidity, pressure);});
}

void WeatherData::measurementsChanged( )
{
	notifyObserver( );
}

void WeatherData::setMeasurements(float temp, float humidity, float pressure)
{
	this->temp = temp;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged( );
}
#endif // !WEATHERDATA_H
