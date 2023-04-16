#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll a[5002], b[5002], c[5002];
ll tb[5002];
int main()
{
	int i, k, j, l, m, n, o, p;
	cin >> n;
	for (j = 0; j < n; j++)
	{
		cin >> a[j];
	}
	for (j = 0; j < n; j++)
	{
		cin >> b[j];
		for (i = 0; i < n; i++)
		{
			if (a[i] < b[j])
			{
				tb[j]++;
			}
		}
	}
	ll res = 0;
	for (j = 0; j < n; j++)
	{
		cin >> c[j];
		for (i = 0; i < n; i++)
		{
			if (c[j] > b[i])
			{
				res += tb[i];
			}
		}
	}
	/*
4
12 6 8 3
1 3 5 8
9 15 7 5

4
3 6 8 12
1 3 5 8
5 7 9 15
*/


	cout << res;

	return 0;
}