#include <iostream>
using namespace std;
typedef long long ll;

const int N = 500005;
ll s[N], mn[N], mx[N], a[N];
int main()
{
	int n, i, j, k;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> a[i];
	s[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--)
		s[i] = a[i] + s[i + 1];
	mn[n - 1] = s[n - 1];
	mx[n - 1] = s[n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		mn[i] = min(s[i], mn[i + 1]);
		mx[i] = max(s[i], mx[i + 1]);
	}
	/*for (i = 0; i < n; i++)
		cout << mx[i] << ' ';
	cout << endl;
	for (i = 0; i < n; i++)
		cout << mn[i] << ' ';
	cout << endl;*/
	bool b = 1;
	ll res = s[0];
	for (i = 0; i < n && k; i++)
	{
		if (b)
		{
			if (mx[i] == s[i])
			{
				k--;
				b = 0;
				s[0] -= 2 * mx[i];
				res = min(res, s[0]);
			}
		}
		else
		{
			if (mn[i] == s[i])
			{
				k--;
				b = 1;
				s[0] += 2 * mn[i];
				res = min(res, s[0]);
			}
		}
	}
	cout << res;

	return 0;
}