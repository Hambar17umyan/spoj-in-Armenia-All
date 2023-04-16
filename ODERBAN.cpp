#include <iostream>
using namespace std;
#define ll long long
#define poss pos*2
#define midd mid+1

const int N = 100005;
ll arr[N], t[4 * N], prr[4 * N], pr[N];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		t[pos] = arr[l];
		pr[l] = pos;
		prr[pos] = l;
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = max(t[poss], t[poss + 1]);
}
ll query(ll k, ll pos, ll x)
{
	if (t[pos] < x)
	{
		return -1;
	}
	if (prr[pos] != 0)
	{
		if (prr[pos] >= k)
		{
			return -1;
		}
		else
		{
			return prr[pos];
		}
	}
	if (t[poss] >= x)
	{
		return query(k, poss, x);
	}
}
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, n - 1, 1);
	string h = "OOPS\n";
	cout << h;
	for (i = 1; i < n; i++)
	{
		o = query(i, pr[i], arr[i]);
		if (o == -1)
		{
			cout << h;
		}
		else
		{
			cout << o << endl;
		}
	}

	return 0;
}