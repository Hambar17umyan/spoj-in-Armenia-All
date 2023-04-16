#include <iostream>
using namespace std;

long long arr[305];
int main()
{
	long long i, j, k = 0, l, m, n, o, p;
	cin >> n >> o;
	long long z = 0;
	bool b = false;
	long long mx = -30000000008;
	long long fz = -1, fk = -1, lz, lk;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > mx)
			mx = arr[i];
		if (arr[i] >= 0)
			b = true;
		k += (i % 2 == 0) * (arr[i] >= 0) * arr[i];
		z += (i % 2 == 1) * (arr[i] >= 0) * arr[i];
		if (i % 2)
		{
			if (arr[i] >= 0)
			{
				if (fk == -1)
					fk = i;
				lk = i;
			}
		}
		else
		{
			if (arr[i] >= 0)
			{
				if (fz == -1)
					fz = i;
				lz = i;
			}
		}
	}
	if (!b)
	{
		cout << mx << endl;
		return 0;
	}
	else
	{
		cout << max(k, z);
	}

	return 0;
}