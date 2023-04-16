#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
#define ll long long
#define poss pos * 2
#define midd mid + 1
#define middle ll mid = (l + r) / 2
#define v it->second

ll arr[1000006];
ll prr[1000006];
map<ll, vector<ll>>mp;
ll t[4000006];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		t[pos] = arr[l];
		prr[r] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = min(t[poss], t[poss + 1]);
}
ll find(ll ql, ll qr, ll l, ll r, ll pos)//ql qr->pahanjvogh//l r->nerka
{
	middle;
	if (ql == l && qr == r)
	{
		return t[pos];
	}
	else if (qr < mid + 1)
	{
		return find(ql, qr, l, mid, poss);
	}
	else if (ql > mid)
	{
		return find(ql, qr, midd, r, poss + 1);
	}
	else
	{
		return min(find(ql, mid, l, mid, poss), find(midd, qr, midd, r, poss + 1));
	}
}
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		mp[arr[i]].push_back(i);
	}
	ll res = 0;
	build(0, n - 1, 1);
	map<ll, vector<ll>>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		for (i = 0; i < v.size() - 1; i++)
		{
			if (v[i] == v[i + 1] - 1)
			{
				res++;
			}
			else
			{
				k = find(v[i] + 1, v[i + 1] - 1, 0, n - 1, 1);
				if (k > it->first)
					res++;
			}
		}
	}
	printf("%lld", res);

	return 0;
}