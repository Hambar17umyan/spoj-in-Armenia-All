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

pair<pair<int, int>, pair<int, int>>uxx[10005];
int s[10005];
int pole[11005][11005];
pair<int, int>uu[11005];
map<int, int>mp;
void solve()
{
	int n, i, j, k;
	int mxx, mxy;
	cin >> mxx >> mxy;
	int sl = mxx * mxy;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> uxx[i].first.first >> uxx[i].first.second >> uxx[i].second.first >> uxx[i].second.second;
		uu[i] = uxx[i].first;
		int a, b, c, d;
		a = uxx[i].first.first;
		b = uxx[i].first.second;
		c = uxx[i].second.first;
		d = uxx[i].second.second;
		s[i] = c * d;
		for (j = b; j <= b + d; j++)
		{
			pole[j][a]++;
			if (a + c != n - 1)
			{
				pole[j][a + c + 1]--;
			}
		}
		uxx[i].first.first += c;
		uxx[i].first.second += d;
	}
	if (n == 1)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a, b;
			cin >> a >> b;
			if (uxx[0].first.first <= a && uxx[0].first.second <= b && uxx[0].second.first >= a && uxx[0].second.second >= b)
			{
				cout << s[0] << endl;
			}
			else cout << sl - s[0];
		}
		return;
	}
	for (i = 0; i <= mxx; i++)
	{
		int k = 0;
		for (j = 0; j <= mxy; j++)
		{
			k += pole[i][j];
			pole[i][j] = k;
		}
	}
	for (i = 0; i < n; i++)
	{
		int yy = pole[uu[i].first][uu[i].second];
		mp[yy] = i;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << s[mp[pole[a][b]]] << endl;
	}
}

int main()
{
	solve();

	return 0;
}
