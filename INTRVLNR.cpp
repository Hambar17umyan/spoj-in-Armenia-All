#include <iostream>
using namespace std;
typedef long long ll;

const int N = 10008;
int arr[N];
pair<int, int>p[N];
int pr[N];

void solve()
{
	int i, j, n, k;
	cin >> n;
	for (i = 0; i < N - 2; i++)
	{
		arr[i] = 0;
		pr[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
		p[i].first++;
		arr[p[i].first]++;
		arr[p[i].second + 1]--;
	}
	k = 0;
	int l = 0;
	for (i = 1; i < 10001; i++)
	{
		k += arr[i];
		arr[i] = k;
		if (k == 0)
		{
			//cout << i << ' ';
			cout << "WA\n";
			return;
		}
		if (k == 1)
		{
			pr[i] = l + 1;
			l++;
		}
		else
			pr[i] = l;
	}
	for (i = 0; i < n; i++)
	{
		if (pr[p[i].second] == pr[p[i].first - 1])
		{
			cout << "WA\n";
			return;
		}
	}
	cout << "OK\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();


	return 0;
}