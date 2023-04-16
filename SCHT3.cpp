#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

pair<ll, ll>arr[1000005];
queue<pair<ll, ll>>q;
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);
	k = 0;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i].first == 0)
			{
				break;
			}
			if (arr[j].first == 0)
			{
				continue;
			}
			arr[j].first--;
			arr[i].first--;
			q.push(make_pair(arr[i].second, arr[j].second));
		}
		if (arr[i].first != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	o = q.size();
	while (o--)
	{
		cout << min(q.front().first, q.front().second) << ' ' << max(q.front().first, q.front().second) << endl;
		q.pop();
	}

	return 0;
}