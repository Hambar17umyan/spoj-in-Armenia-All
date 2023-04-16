#include <iostream>
using namespace std;

int arr[200005];
int sf[200005];
int main()
{
	int i, j, k, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	k = 0;
	for (i = n - 1; i >= 0; i--)
	{
		sf[i] = k;
		k += (arr[i] > 0);
	}
	int res = 0;
	for (i = 0; i < n; i++)
	{
		if (sf[i] + arr[i] > res)
			res = sf[i] + arr[i];
	}
	k = 0;
	cout << res << endl;
	for (i = n - 1; i >= 0; i--)
	{
		sf[i] = k;
		if (arr[i] == i)
			k++;
	}
	res = n;
	for (i = 0; i < n; i++)
	{
		if (sf[i] + arr[i] < res)
			res = sf[i] + arr[i];
	}
	cout << res;

	return 0;
}