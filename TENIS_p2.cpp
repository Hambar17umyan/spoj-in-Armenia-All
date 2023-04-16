#include <iostream>
#pragma warning(disable : 4996)
#include <deque>
#define ll long long
using namespace std;

ll h[100005];
pair<ll, ll> ans[100005];
pair<ll, ll> ans1[100005];

int main()
{
	ll i = 0, j = 0, k = 0, l, m = 0, n = 0, o = 0, p = 0, q = 0;
	cin >> n;
	deque<ll>u;
	if (n == 2)
	{
		cin >> o >> p;
		cin >> q;
		while (q--)
		{
			cin >> o;
			cout << 2 << ' ' << 1 << endl;
		}
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lli", &h[i]);
		if (h[i] == n)
		{
			k = i;
		}
		else u.push_back(h[i]);
	}
	if (k == 0)
	{
		for (i = 1; i <= n - 1; i++)
		{
			u.push_back(u.front());
			ans1[i] = make_pair(n, u.front());
			u.pop_front();
		}
		scanf("%lli", &q);
		for (i = 0; i < q; i++)
		{
			scanf("%lli", &m);
			o = m % (n - 1);
			if (o == 0)
			{
				o = n - 1;
			}
			printf("%lli", ans1[o].first);
			printf("%c", ' ');
			printf("%lli", ans1[o].second);
			printf("%c", '\n');
		}

		return 0;
	}
	for (i = 1; i < k; i++)
	{
		o = u.front();
		u.pop_front();
		p = u.front();
		u.pop_front();
		u.push_back(min(o, p));
		u.push_front(max(o, p));
		ans[i] = make_pair(max(o, p), min(o, p));
	}
	for (i = 0; i < n - 1; i++)
	{
		ans1[i] = make_pair(n, u.front());
		u.push_back(u.front());
		u.pop_front();
	}
	scanf("%lli", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%lli", &m);
		if (m < k)
		{
			printf("%lli", ans[m].first);
			printf("%c", ' ');
			printf("%lli", ans[m].second);
			printf("%c", '\n');
		}
		else
		{
			printf("%lli", ans1[(m - k) % (n - 1)].first);
			printf("%c", ' ');
			printf("%lli", ans1[(m - k) % (n - 1)].second);
			printf("%c", '\n');
		}
	}
}