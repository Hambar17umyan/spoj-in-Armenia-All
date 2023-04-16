#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>>mp;
map<int, vector<int>>d;
int res[100005];
int main()
{
	int i, j, n, m, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			mp[i].push_back(4);
			d[i].push_back(1);
			cin >> mp[i][j];
		}
	}
	res[0] = 1;
	for (i = 1; i < n; i++)
	{
		int y = 1;
		for (j = 0; j < m; j++)
		{
			if (mp[i][j] >= mp[i - 1][j])
			{
				d[i][j] = d[i - 1][j] + 1;
			}
			if (d[i][j] > y)
				y = d[i][j];
		}
		res[i] = y;
	}
	cin >> k;
	//cout << "fffffffffff";
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (res[b] >= b - a + 1)
		{
			cout << "Yes\n";
		}
		else cout << "No\n";
	}

	return 0;
}