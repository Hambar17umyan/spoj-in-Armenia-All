#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
typedef long long ll;
#define usg unsigned
#define kap map
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define rev(x) reverse(x.begin(), x.end())
#define _CRT_SECURE_NO_WARNINGS
//scanf("%d", &n);
//printf("%c", '\n');
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

string to2(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	rev(r);

	return r;
}

ll binpow(ll a, ll b)
{
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

vector<int>g[100005];
ll g5[1005][1005];
bool color[1005];
void rec(int pr, int ind, int k)
{
	k++;
	color[ind] = true;
	for (int i = 0; i < g[ind].size(); i++)
	{
		if (!color[g[ind][i]]) 
		{
			g5[g[ind][i]][pr] = k;
			rec(pr, g[ind][i], k);
		}
	}
}
void solve()
{
	ll n, k, i, j;
	cin >> n >> k;
	bool e1, e2, e3, e4, e5;
	e1 = e2 = e3 = e4 = e5 = true;
	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
		if (u != i + 1 || v != i + 2)
		{
			e3 = false;
		}
	}
	if (g[0].size() == n - 1)
	{
		ll res;
		ll z = 0;
		if (k == 0)
		{
			res = (n * (n - 1)) / 2;
			cout << max(res, z) << endl;
		}
		else if (k == 1)
		{
			res = ((n - 1) * (n - 2)) / 2;
			cout << max(res, z) << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		return;
	}
	if (k <= 2)
	{
		ll res = 0;
		if (k == 0)
		{
			ll z = 0;
			res = (n * (n - 1)) / 2;
			cout << max(res, z) << endl;
		}
		else if (k == 1)
		{
			ll z = 0;
			res = (n * (n - 1)) / 2 - n + 1;
			cout << max(res, z) << endl;
		}
		else
		{
			ll y = n - 1;
			for (i = 0; i < n; i++)
			{
				if (g[i].size() > 1)
				{
					y += (g[i].size() * (g[i].size() - 1)) / 2;
				}
			}
			ll z = 0;
			res = (n * (n - 1)) / 2 - y;
			cout << max(res, z) << endl;
		}
		return;
	}
	else if (n <= 1000)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				color[j] = false;
			}
			rec(i, i, 0);
		}
		ll res = 0;
		for (i = 0; i < n + 1; i++)
		{
			for (j = i + 1; j < n + 1; j++)
			{
				if (g5[i][j] > k)
				{
					res++;
				}
			}
		}
		cout << res << endl;
	}
	else
	{
		ll res = 0;
		for (i = n - 1; i > k; i--)
		{
			res += n - i;
		}
		cout << res << endl;
		return;
	}
}

int main()
{
	solve();

	return 0;
}
