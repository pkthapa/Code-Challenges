// Given a sorted integer array, find a pair which sums to given num (sum).

bool isPairWithSum(vector<int> a, int sum)
{
	int low = 0;
	int high = a.size() - 1;

	while (low < high)
	{
		int temp = a[low] + a[high];

		if (temp == sum)
		{
			return true;
		}
		if (temp < sum)
		{
			++low;
		}
		else
		{
			--high;
		}
	}
	return false;
}

int main()
{
	vector<int> a = {1, 2, 4, 4, 5, 6, 7, 8, 9, 9};
	cout << boolalpha << isPairWithSum(a, 18) << endl;
	return 0;
}