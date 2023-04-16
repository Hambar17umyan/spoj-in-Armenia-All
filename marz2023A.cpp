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

ll a[200005];
void solve()
{
	ll n, i, j;
	cin >> n;
	bool ent1 = true;
	short k1r = 0;
	ll sumx2 = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	int ut1 = t;
	queue<pair<short, ll>>q;
	while (t--)
	{
		short op;
		ll k;
		cin >> op >> k;
		q.push(make_pair(op, k));
		if (op < k1r)
		{
			ent1 = false;
		}
		if (op == 3)
			sumx2 += k;
		k1r = op;
	}
	if (ent1)
	{
		set<ll>bazm;
		while (!q.empty())
		{
			pair<short, ll>p = q.front();
			if (p.first == 1)
			{
				bazm.insert(p.second);
			}
			else if (p.first == 2)
			{
				set<ll>::iterator it = bazm.find(p.second);
				bazm.erase(it);
			}
			else if (p.first == 3)
			{
				q.pop();
				continue;
			}
			else if (p.first == 4)
			{
				break;
			}
			q.pop();
		}
		for (set<ll>::iterator it = bazm.begin(); it != bazm.end(); it++)
		{
			a[*it - 1] += sumx2;
		}
		while (!q.empty())
		{
			pair<short, ll>p = q.front();
			cout << a[p.second - 1] << endl;
			q.pop();
		}
	}
	else
	{
		set<ll>bazm;
		while (!q.empty())
		{
			pair<short, ll>p;
			p = q.front();
			if (p.first == 1)
			{
				bazm.insert(p.second);
			}
			else if (p.first == 2)
			{
				bazm.erase(bazm.find(p.second));
			}
			else if (p.first == 3)
			{
				for (set<ll>::iterator it = bazm.begin(); it != bazm.end(); it++)
				{
					a[(*it) - 1] += p.second;
				}
			}
			else
			{
				cout << a[p.second - 1] << endl;
			}
			q.pop();
		}
	}
}

int main()
{
	solve();

	return 0;
}
