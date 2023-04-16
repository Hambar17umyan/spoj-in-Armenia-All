#include <iostream>
using namespace std;
typedef long long ll;

const int N = 62;

pair<ll, ll>p[N * N];
ll d[N * N];

ll k = 0;
void rec(ll ind)
{
	ll a, b;
	a = p[ind].first;
	b = p[ind].second;
	ll r = 1;
	for (ll i = 0; i < k; i++)
	{
		if (p[i].first > a && p[i].second < b)
		{
			if (d[i] == 0)
			{
				rec(i);
			}
			r += d[i];
		}
	}
	d[ind] = r;
}
int main()
{
	ll i, j, n, m;
	string s;
	cin >> s;
	n = s.size();
	k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (s[i] == s[j])
			{
				p[k] = make_pair(i, j);
				if (i == j)
				{
					d[k] = 1;
				}
				k++;
			}
		}
	}
	ll res = 0;
	for (i = 0; i < k; i++)
	{
		if (d[i] == 0)
		{
			rec(i);
		}
		res += d[i];
	}
	cout << res << endl;

	return 0;
}