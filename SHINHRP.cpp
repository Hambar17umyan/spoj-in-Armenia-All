#include <iostream>
#include <vector>
#define ll long long
using namespace std;

pair<ll, ll>arr[52];
ll R[52];
vector<ll>start;
vector<ll>g[52];
pair<ll, ll> points[32];
vector<ll>tp;
ll dist2(ll x1, ll y1, ll x2, ll y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool xx[52];
void rec(ll ind, bool color[])
{
	color[ind] = true;
	tp.push_back(ind);
	for (ll i = 0; i < g[ind].size(); i++)
	{
		if (color[g[ind][i]] == false)
		{
			rec(g[ind][i], color);
		}
	}
}
int main()
{
	ll i, j, k, l, m, n, o, p;
	ll x, y;
	cin >> x >> y;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second >> R[i];
		if (R[i] * R[i] >= dist2(arr[i].first, arr[i].second, x / 2, 0))
		{
			start.push_back(i);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if ((R[i] + R[j]) * (R[i] + R[j]) >= dist2(arr[i].first, arr[i].second, arr[j].first, arr[j].second))
			{
				g[i].push_back(j);
				g[i].push_back(i);
			}
		}
	}
	cin >> k;
	for (i = 0; i < start.size(); i++)
	{
		rec(start[i], xx);
	}
	for (i = 0; i < k; i++)
	{
		cin >> points[i].first >> points[i].second;
		if (points[i].first == x / 2 && points[i].second == 0)
		{
			cout << "YES\n";
			continue;
		}
		bool bl = true;
		for (j = 0; j < tp.size(); j++)
		{
			ll y = tp[j];
			if (R[y] * R[y] >= dist2(arr[y].first, arr[y].second, points[i].first, points[i].second))
			{
				cout << "YES\n";
				bl = false;
				break;
			}
		}
		if (bl)
			cout << "NO\n";
	}

	return 0;
}