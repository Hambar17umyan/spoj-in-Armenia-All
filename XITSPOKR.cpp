#include <iostream>
using namespace std;
typedef long long ll;

bool arr[200005];

int main()
{
	ll i, j, n, k, m, x;
	cin >> n >> x;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	k = 0;
	ll res = 1;
	ll a = 0;
	for (i = 0; i < n; i++)
	{
		k <<= 1;
		k += (arr[i]);
		if (k >= x)
		{
			while (true)
			{
				if (arr[a] != 0)
				{
					k -= (1 << (i - a));
					break;
				}
				a++;
			}
			a++;
		}
		res += i - a + 1;
	}
	cout << res - 1 << endl;

	return 0;
}