#include "main.h"

// Driver code
int main()
{
	Singleton *instance = Singleton::createSingleton();
	instance->changeCount();
	cout << instance->getCount() << endl;

	Singleton *instance1 = Singleton::createSingleton();
	instance1->changeCount();
	cout << instance1->getCount() << endl;
	return 0;
}
/*
Output:
1
2
*/