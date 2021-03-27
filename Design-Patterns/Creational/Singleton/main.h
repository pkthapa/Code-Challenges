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

class Singleton
{
	static int count;
	static Singleton *p;
	Singleton()
	{
	}

public:
	static Singleton *createSingleton()
	{
		if (nullptr == p)
		{
			p = new Singleton;
		}
		return p;
	}

	void changeCount()
	{
		++count;
	}

	int getCount() const
	{
		return count;
	}
};
int Singleton::count = 0;
Singleton *Singleton::p = nullptr;

#endif /* MAIN_H_ */
