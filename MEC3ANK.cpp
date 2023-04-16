#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll arr[200007];

int main()
{
	int i, j, n;
	cin >> n;
	ll sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	ll w = 0;
	ll q = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (sum - w - arr[i] > arr[i] + w)
		{
			w += arr[i];
		}
		else q = max(arr[i], q);
	}
	if (w < q)
	{
		cout << "no\n";
	}
	else
	{

	}

	return 0;
}