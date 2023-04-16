#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

vector<int>pb[2000006];
bool bl[2000006];
int getlog(ll a, ll p)
{
	int k = 0;
	while (a % p == 0)
	{
		a /= p;
		k++;
	}
	return k;
}
void lynx(ll r)
{
	ll j, i;
	for (i = 2; i <= r; i++)
	{
		if (bl[i])
			continue;
		for (j = i; j <= r; j += i)
		{
			bl[j] = true;
			pb[j].push_back(i);
		}
	}
}
ll binpow(ll a, ll b)
{
	ll res = 1;
	while (b > 0) 
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
ll getres(ll a, ll b)
{
	ll res = 1;
	set<ll>st;
	for (int i = 0; i < pb[a].size(); i++)
	{
		ll u = 0;
		if (b % pb[a][i] == 0)
		{
			u += getlog(b, pb[a][i]);
			st.insert(pb[a][i]);
		}
		u += getlog(a, pb[a][i]);
		res *= binpow(pb[a][i], u/2);
	}
	for (int i = 0; i < pb[b].size(); i++)
	{
		if (st.find(pb[b][i]) != st.end())
		{
			continue;
		}
		ll u = 0;
		if (a % pb[b][i] == 0)
		{
			u += getlog(a, pb[b][i]);
			st.insert(pb[b][i]);
		}
		u += getlog(b, pb[b][i]);
		res *= binpow(pb[b][i], u/2);
	}
	return res;
}

int main()
{
	int i, j, q, n;
	cin >> n >> q;
	lynx(n);
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << getres(a, b) << ' ';
	}

	return 0;
}