#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
vector<long long> a, b, c;
#define all(x) x.begin(), x.end()
int main()
{
	int i, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		a.push_back(0);
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		b.push_back(0);
		cin >> b[i];
	}
	for (i = 0; i < n; i++)
	{
		c.push_back(0);
		cin >> c[i];
	}
	sort(all(a));
	sort(all(b));
	sort(all(c));
	long long res = 0;
	for (i = 0; i < n; i++)
	{
		long long k;
		k = n - (upper_bound(all(c), b[i]) - c.begin());
		k *= (lower_bound(all(a), b[i]) - a.begin());
		res += k;
	}
	cout << res;

	return 0;
}