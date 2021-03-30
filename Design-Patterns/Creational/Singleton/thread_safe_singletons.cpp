/////////////////////////////////////////////////////////////////////////////////////
// 1st approach: This approach is very costly. We are executing critical section code for every threads everytime 'getInstance()' is called.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <mutex>

mutex m;

class Singleton
{
	Singleton(){}
	static Singleton *instance;
public:
	static Singleton *getInstance()
	{
		m.lock(); // Entry critical section.
		if (instance == nullptr)
		{
			instance = new Singleton;
		}
		m.unlock(); // Exit critical section.
		return instance;
	}
};
Singleton *Singleton::instance = nullptr;

/////////////////////////////////////////////////////////////////////////////////////
// 2nd approach: Eager Instantiation.
// In this solution, no critical section is involved. But this is not a good design, since this design is against the basic OOAD design principle of Lazy/Late Instantiation.
// We should create an object only when required, but not upfront.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
	Singleton(){}
	static Singleton *instance;
public:
	static Singleton *getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton;
		}
		return instance;
	}
};
Singleton *Singleton::instance = nullptr;

int main()
{
	Singleton *instance = Singleton::getInstance(); // Eager Instantiation done here.

	// Imaging thousands of lines of code here.

	// Create threads from here.
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// 3rd approach: Double 'instance' checking. We are checking 'instance' check everytime before executing critical section entry/exit.
// This is less costly.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <mutex>
using namespace std;

mutex m;

class Singleton
{
	Singleton(){}
	static Singleton *instance;
public:
	static Singleton *getInstance()
	{
		if (instance == nullptr)
		{
			m.lock();
			if (instance == nullptr)
			{
				instance = new Singleton;
			}
			m.unlock();
		}
		return instance;
	}
};
Singleton *Singleton::instance = nullptr;

/////////////////////////////////////////////////////////////////////////////////////
// 4th approach: Meyers Singleton.
// It is automatically thread safe, since we are creating a static Singleton object.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Singleton
{
	Singleton(){}
public:
	static Singleton *getInstance()
	{
		static Singleton s; // Create and return static object.
		return &s;
	}
};