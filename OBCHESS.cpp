#include <iostream>
using namespace std;

int arr[10][10];
int main()
{
	int i, j, k, l, m, n, o, p;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
		}
	}
	int res = 0;
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 6; j++)
		{
			k = arr[i][j];
			k += arr[i][j + 1];
			k += arr[i + 1][j + 1];
			k += arr[i + 1][j];
			if (abs(arr[i][j]) == 4 || abs(arr[i][j + 1]) == 4 || abs(arr[i + 1][j + 1]) == 4 || abs(arr[i + 1][j]) == 4)
			{
				continue;
			}
			if (k > res)
				res = k;
		}
	}
	cout << res;

	return 0;
}