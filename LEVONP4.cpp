#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 1000006;
set<pair<int, int>>p;
int sw[N], ps[N];
int ans[N];

bool operator <(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first < b.first)
		return true;
	if (a.first > b.first)
		return false;
	if (a.second > b.second)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, n;
	cin >> n;
	int h;
	cin >> h;
	for (i = 0; i < n; i++)
	{
		cin >> ps[i];
		p.insert(make_pair(ps[i], i));
	}
	for (i = 0; i < n; i++)
	{
		cin >> sw[i];
	}
	ans[0] = -1;
	ans[1] = sw[0] + sw[1];
	int k = max(sw[0], sw[1]);
	for (i = 2; i < n; i++)
	{
		ans[i] = max(sw[i] + k, ans[i - 1]);
		k = max(k, sw[i]);
	}
	int res = -1;
	for (i = n - 1; i > 1; i--)
	{
		if (ps[i] > h)
		{
			continue;
		}
		set<pair<int, int>>::iterator it = upper_bound(p.begin(), p.end(), make_pair(h - ps[i], n));
		if (it == p.end())
			continue;
		pair<int, int>u = *it;
		if (u.second - 1 >= i)
			continue;
		if (ans[u.second - 1] != -1)
		{
			res = max(ans[u.second - 1] + sw[i], res);
		}
	}
	cout << res;

	return 0;
}