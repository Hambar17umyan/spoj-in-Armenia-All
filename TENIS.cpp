#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[100005];
pair<int, int> res[100005], rmod[100005];
int main()
{
	int i, j, n;
	cin >> n;
	int y = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == n)
		{
			y = i;
		}
	}
	int prepl = 0;
	if (y == 0 || y == 1)
	{
		prepl = 0;
	}
	else
	{
		prepl = y;
	}
	queue<int>st;
	int k = 0;
	for (i = 0, j = 1; ; k++)
	{
		if (i == y)
		{
			break;
		}
		if (arr[i] > arr[j])
		{
			res[k] = make_pair(arr[i], arr[j]);
			st.push(arr[j]);
			j++;
		}
		else
		{
			res[k] = make_pair(arr[j], arr[i]);
			st.push(arr[i]);
			i = j;
			j++;
		}
	}
	k = 0;
	for (i = y + 1; i < n; i++)
	{
		rmod[i - y] = make_pair(n, arr[i + 1]);
		k++;
	}
	rmod[n - 1] = make_pair(n, res[prepl].second);
	while (!st.empty())
	{
		rmod[k] = make_pair(n, st.front());
		k++;
		st.pop();
	}
	int q;
	/*for (i = 0; i < n - 1; i++)
		cout << rmod[i].first << '-' << rmod[i].second << ' ';*/
	cout << endl;
	cin >> q;
	while (q--)
	{
		int w;
		cin >> w;
		if (w <= prepl)
		{
			cout << res[w - 1].first << ' ' << res[w - 1].second << endl;
		}
		else
		{
			w -= prepl;
			w--;
			w %= (n - 1);
			cout << rmod[w].first << ' ' << rmod[w].second << endl;
		}
	}

	return 0;
}