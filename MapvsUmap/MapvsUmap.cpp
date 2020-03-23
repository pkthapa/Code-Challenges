#include <iostream>

typedef long long LL;
#define COUNT 1000000
int main()
{
	clock_t t = clock();
	std::map<LL, std::string> m;

	for(LL i = 0l; i < COUNT; i++)
	{
		m[i] = "pankaj-piyali";
	}
	std::cout << "storing map ET = " << double(clock() - t)/CLOCKS_PER_SEC << std::endl;
	
	t = clock();
	if(m.find(COUNT - 2) != m.end())
	{
		std::cout << "m found" << std::endl;
	}
	else
	{
		std::cout << "m not found" << std::endl;
	}
	std::cout << "accessing map ET = " << double(clock() - t)/CLOCKS_PER_SEC << std::endl;
	//--------------------------------------	
	t = clock();
	std::unordered_map<LL, std::string> um;

	for(LL i = 0l; i < COUNT; i++)
	{
		um[i] = "pankaj-piyali";
	}
	std::cout << "storing umap ET = " << double(clock() - t)/CLOCKS_PER_SEC << std::endl;
	
	t = clock();
	if(m.find(COUNT - 2) != m.end())
	{
		std::cout << "um found" << std::endl;
	}
	else
	{
		std::cout << "um not found" << std::endl;
	}
	std::cout << "accessing umap ET = " << double(clock() - t)/CLOCKS_PER_SEC << std::endl;
	return 0;
}
