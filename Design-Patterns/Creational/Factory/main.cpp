#include "main.h"

class Client
{
	Vehicle *vptr;
public:
	Client(VEHICLE_TYPES type) : vptr(nullptr)
	{
		vptr = Vehicle::createVehicle(type);
	}
	Vehicle *getVehicle()
	{
		return vptr;
	}
};

// Driver code
int main()
{
	Client *client = new Client(THREE);
	client->getVehicle()->printVehicle();
	return 0;
}
