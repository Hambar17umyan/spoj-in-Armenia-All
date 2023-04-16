#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

int main()
{
	string s;
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	s = to_string(n);
	m = s.size();
	k = 0;
	for (i = 0; i < m; i++)
	{
		k *= 10;
		k += 9 - i;
	}
	if (k <= n )
	{
		if (m == 9)
		{
			cout << 0;
			return 0;
		}
		for (i = 1; i <= m + 1; i++)
		{
			cout << i;
		}
	}
	else
	{
		int arr[12];
		ll res = 3333333333333;
		for (i = 0; i < 9; i++)
		{
			arr[i] = i + 1;
		}
		do
		{
			k = 0;
			for (i = 0; i < m; i++)
			{
				k *= 10;
				k += arr[i];
			}
			if (k > n)
			{
				res = min(res, k);
			}
		} while (next_permutation(arr, arr + 9));
		if (res == 3333333333333)
		{
			cout << 0;
			return 0;
		}
		cout << res;
	}

	return 0;
}