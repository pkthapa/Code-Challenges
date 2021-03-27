/*
 * main.h
 *
 *  Created on: 23-Mar-2021
 *      Author: Pankaj
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>

using namespace std;

typedef enum
{
	TWO, THREE, FOUR
}VEHICLE_TYPES;

class Vehicle
{
public:
	virtual ~Vehicle(){}
	virtual void printVehicle() = 0;
	static Vehicle* createVehicle(VEHICLE_TYPES type);
};

class TwoWheeler : public Vehicle
{
public:
	void printVehicle()
	{
		cout << "Two wheeler" << endl;
	}
};

class FourWheeler : public Vehicle
{
public:
	void printVehicle()
	{
		cout << "Four wheeler" << endl;
	}
};

class ThreeWheeler : public Vehicle
{
public:
	void printVehicle()
	{
		cout << "Three wheeler" << endl;
	}
};

Vehicle* Vehicle::createVehicle(VEHICLE_TYPES type)
{
	if (TWO == type)
	{
		return new TwoWheeler;
	}
	else if (FOUR == type)
	{
		return new FourWheeler;
	}
	else if (THREE == type)
	{
		return new ThreeWheeler;
	}
	return nullptr;
}

#endif /* MAIN_H_ */