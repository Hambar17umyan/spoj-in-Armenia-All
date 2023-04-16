#include <iostream>
using namespace std;
typedef long long ll;

ll arr[100005];
int main()
{
	ll n, k = 1;
	cin >> n;
	if (n <= 4)
	{
		cout << n << endl;
		return 0;
	}
	arr[1] = 4;
	ll m = n;
	n -= 4;
	for (ll i = 2; ; i++)
	{
		arr[i] = arr[i - 1] * 4;
		k = i;
		if (arr[i] >= n)
			break;
		n -= arr[i];
	}
	//cout << k << endl;
	ll res = 0;
	m = n;
	for (ll i = k - 1; i >= 1; i--)
	{
		ll w = m / arr[i];
		if (m % arr[i] != 0)
			w++;
		m = m % arr[i];
		res *= 10;
		res += w;
		if (m == 0)
		{
			
			while (i--)
			{
				res *= 10;
				res += 4;
			}
			break;
		}
	}
	if (m != 0)
	{
		res *= 10;
		res += m;
	}
	cout << res;

	return 0;
}