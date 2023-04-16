#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define inf 100000000000000
#define ll long long
using namespace std;

vector<pair<ll, ll>>g[1002];
bool c[1002];
ll r[1002];
priority_queue<pair<ll, ll>>pq;

int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> o >> p >> k;
		c[o] = 0;
		c[p] = 0;
		g[o].push_back(make_pair(p, k));
		g[p].push_back(make_pair(o, k));
		if (o != 1)
		{
			if (r[o] == 0)
				pq.push(make_pair(-inf, o));
			r[o] = inf;
		}
		if (p != 1)
		{
			if (r[p] == 0)
				pq.push(make_pair(-inf, p));
			r[p] = inf;
		}
	}
	r[1] = 0;
	pq.push(make_pair(0, 1));
	while (pq.size() != 0)
	{
		pair<ll, ll>x;
		x = pq.top();
		ll x1, x2;
		x1 = -x.first;
		x2 = x.second;
		pq.pop();
		if (r[x2] != x1)
		{
			continue;
		}
		if (c[x2])
			continue;
		c[x2] = true;
		for (i = 0; i < g[x2].size(); i++)
		{
			p = max(g[x2][i].second, x1);
			if (p == inf)
			{
				p = g[x2][i].second;
			}
			if (p < r[g[x2][i].first])
			{
				r[g[x2][i].first] = p;
				pq.push(make_pair(-p, g[x2][i].first));
			}
		}
	}
	cout << r[n];

	return 0;
}