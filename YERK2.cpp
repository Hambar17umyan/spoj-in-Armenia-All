#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1000006];
pair<int, int> qrr[1000006];
priority_queue<pair<int, int>>ans;
bool brr[1000006];
map<int, vector<int>> mp;
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		mp[arr[i]].push_back(i);
	}
	map<int, vector<int>>::iterator it = mp.begin();
	if (n == 1)
	{
		for (i = 0; i < m; i++)
		{
			cin >> o;
			if (o < arr[0])
			{
				cout << 1 << ' ';
			}
			else cout << 0 << ' ';
		}
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		cin >> qrr[i].first;
		qrr[i].second = i;
	}
	sort(qrr, qrr + m);
	k = 1;
	for (i = 0; i < m; i++)
	{
		pair<int, int>y = qrr[i];
		o = qrr[i].first;
		p = qrr[i].second;
		while (it != mp.end())
		{
			if (it->first > o)
			{
				break;
			}
			for (j = 0; j < it->second.size(); j++)
			{
				brr[it->second[j]] = 1;
				if (it->second[j] == 0)
				{
					if (brr[1] == 1)
					{
						k--;
					}
				}
				else if (it->second[j] == n - 1)
				{
					if (brr[n - 2] == 1)
					{
						k--;
					}
				}
				else
				{
					if (brr[it->second[j] - 1] == 0 && brr[it->second[j] + 1] == 0)
					{
						k++;
					}
					else if (brr[it->second[j] - 1] == 1 && brr[it->second[j] + 1] == 1)
					{
						k--;
					}
				}
			}

			it++;
		}

		ans.push(make_pair((-1) * p, k));
	}
	while (ans.size() != 0)
	{
		cout << ans.top().second << ' ';
		ans.pop();
	}

	return 0;
}