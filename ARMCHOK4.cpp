#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int N = 50005;
int arr[N], d[N];
map<int, int>mp;
int main()
{
	int n, i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		if (mp[arr[i]] == 0 || mp[arr[i]] < k)
		{
			mp[arr[i]] = i + 1;
			d[i] = k;
		}
		else
		{
			k = d[i] = mp[arr[i]];
			mp[arr[i]] = i + 1;
		}
	}
	int res = 1;
	for (i = 0; i < n; i++)
	{
		int mx, mn;
		mx = 0;
		mn = 1000000078;
		for (j = i; j >= d[i]; j--)
		{
			if (arr[j] > mx)
				mx = arr[j];
			if (arr[j] < mn)
				mn = arr[j];
			k = i - j + 1;
			if (mx - mn + 1 == k)
			{
				//cout << 'a';
				res = max(res, k);
			}
		}
	}
	cout << res << endl;


	return 0;
}