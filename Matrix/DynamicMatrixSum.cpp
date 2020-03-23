#include <iostream>
using namespace std;

int main()
{
	int r, c;
	cout << "Enter num of rows and col: ";
	cin >> r >> c;

	int **m1 = new int*[r], **m2 = new int*[r], **sum = new int*[r];
	for(int i = 0; i < r; i++)
	{
		m1[i] = new int[c];
		m2[i] = new int[c];
		sum[i] = new int[c];
	}
	
	//int m1[r][c], m2[r][c], sum[r][c];

	cout << "1st matrix: -" << endl;	
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> m1[i][j];
		}
	}
	
	cout << "2nd matrix: -" << endl;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> m2[i][j];
		}
	}

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			sum[i][j] = m1[i][j] + m2[i][j];
		}
	}

	cout << "Sum of matrices:-" << endl;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < r; i++)
	{
		delete[] m1[i];
		delete[] m2[i];
		delete[] sum[i];
	}
	
	delete[] m1;
	delete[] m2;
	delete[] sum;

	return 0;
}
