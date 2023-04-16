#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

map<ll, ll>m;
int main()
{
	int n, i;
	cin >> n;
	vector<ll>arr(n);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	ll res = 0;
	for (map<ll, ll>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second > 1)
		{
			res += ((it->second * (it->second - 1)) / 2) * (lower_bound(arr.begin(), arr.end(), 2 * it->first) - arr.begin() - (it->second));
		}
		if (it->second > 2)
		{
			res += ((it->second - 1) * (it->second - 2) * it->second) / 6;
		}
	}
	cout << res << endl;

	return 0;
}