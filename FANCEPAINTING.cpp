#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int N = 100001;
short c[N];
int arr[N];
pair<int, int>col[N];
int main()
{
	int n;
	cin >> n;
	stack<int>q;
	stack<int>color;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		c[arr[i]]++;
		if (!q.empty())
		{
			if (q.top() == arr[i])
			{
				col[arr[i]].second = i + 1;
				color.push(arr[i]);
				q.pop();
			}
			else if (c[i] > 1)
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				col[arr[i]].first = i + 1;
				q.push(arr[i]);
			}
		}
		else
		{
			if (c[i] > 1)
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				col[arr[i]].first = i + 1;
				q.push(arr[i]);
			}
		}
	}
	int k = n / 2;
	queue<int>after;
	k += q.size();
	cout << k << endl;
	while (!q.empty())
	{
		cout << col[q.top()].first << ' ' << col[q.top()].first << endl;
		q.pop();
	}
	while (!color.empty())
	{
		cout << col[color.top()].first << ' ' << col[color.top()].second << endl;
		color.pop();
	}

	return 0;
}