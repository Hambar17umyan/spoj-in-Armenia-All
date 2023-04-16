#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[25];
int main()
{
	ll n, i, j, k;
	cin >> n >> k;
	for (i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	ll res = 1;
	for (i = 0; i < k; i++)
	{
		res += (n - 1) / (arr[i]);
		for (j = 0; j < i; j++)
		{
			res -= (n - 1) / (arr[i] * arr[j]);
		}
	}
	cout << res;

	return 0;
}