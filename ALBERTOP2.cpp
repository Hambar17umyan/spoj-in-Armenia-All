#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

vector<ll> arr;
int main()
{
	ll i, j, k = 0, l, m, n, o, p, z = 0, mx = -30000000008, mxi;
	cin >> n >> o;
	ll k1 = -1, k2, z1 = -1, z2;
	bool b = true;
	for (i = 0; i < n; i++)
	{
		cin >> o;
		if (o >= mx)
		{
			mxi = i;
			mx = o;
		}
		arr.push_back(o);
		if (i % 2)
		{
			if (arr[i] >= 0)
			{
				b = false;
				z += arr[i];
				if (z1 == -1)
				{
					z1 = i;
				}
				z2 = i;
			}
		}
		else
		{
			if (arr[i] >= 0)
			{
				b = false;
				k += arr[i];
				if (k1 == -1)
				{
					k1 = i;
				}
				k2 = i;
			}
		}
	}
	if (b)
	{
		cout << mx << endl;
		cout << n - 1 << endl;
		for (i = n; i > mxi + 1; i--)
		{
			cout << i << ' ';
		}
		for (i = 0; i < mxi; i++)
		{
			cout << 1 << ' ';
		}
	}

	return 0;
}