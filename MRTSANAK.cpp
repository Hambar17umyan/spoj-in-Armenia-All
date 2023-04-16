#include <iostream>
#define ll long long
using namespace std;

ll a[200005], m[200005], b[200005];
int main()
{
	ll k, n, i, j;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 1; i < n; i++)
		a[i] += a[i - 1];
	b[0] = a[k - 1];
	for (i = 1; i < n - k + 1; i++)
	{
		b[i] = a[i + k - 1] - a[i - 1];
	}
	n = n - k + 1;
	m[n - 1] = b[n - 1];
	for (i = n - 2; i >= 0; i--)
		m[i] = max(m[i + 1], b[i]);
	ll mx = 0;
	ll res = -1;
	for (i = 0; i < k; i++)
	{
		if (res == -1)
		{
			res = m[i + k];
		}
		else
			res = min(res, m[i + k]);
	}
	for (i = k; i < n - k; i++)
	{
		mx = max(b[i - k], mx);
		res = min(res, max(m[i + k], mx));
	}
	mx = max(mx, b[n - 2 * k]);
	cout << min(res, mx);

	return 0;
}