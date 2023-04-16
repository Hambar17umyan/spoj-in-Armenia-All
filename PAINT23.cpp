#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct rect {
	ll a, b, c, d;
	ll s = c * d;
};

rect arr[10005];
ll s[10005];
ll sg[10005];
int par[10005];

bool bina(rect a, rect b)
{
	if (a.a <= b.a && b.c <= a.c && a.b <= b.b && b.d <= a.d)
	{
		return true;
	}
	return false;
}
int main()
{
	ll i, j, n, m;
	ll l0, e0;
	cin >> l0 >> e0;
	ll s0 = l0 * e0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
		arr[i].s = arr[i].c * arr[i].d;
		s[i] = arr[i].s;
		arr[i].c += arr[i].a;
		arr[i].d += arr[i].b;
		par[i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (bina(arr[i], arr[j]))
			{
				if (par[j] == -1)
					par[j] = i;
				else if (s[par[j]] > s[i])
					par[j] = i;
			}
			else if (bina(arr[j], arr[i]))
			{
				if (par[i] == -1)
					par[i] = j;
				else if (s[par[i]] > s[j])
					par[i] = j;
			}
		}
		sg[i] = s[i];
	}
	for (i = 0; i < n; i++)
	{
		if (par[i] != -1)
		{
			sg[par[i]] -= s[i];
		}
		else s0 -= s[i];
	}
	cin >> m;
	while (m--)
	{
		rect q;
		cin >> q.a >> q.b;
		q.c = q.a;
		q.d = q.b;
		int u = -1;
		for (i = 0; i < n; i++)
		{
			if (bina(arr[i], q))
			{
				if (u == -1)
					u = i;
				else if (s[u] > s[i])
					u = i;
			}
		}
		if (u == -1)
		{
			cout << s0 << endl;
			continue;
		}
		cout << sg[u] << endl;
	}

	return 0;
}