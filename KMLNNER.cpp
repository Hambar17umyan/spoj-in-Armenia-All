#include <iostream>
#include <queue>
using namespace std;

int arr[4002][4002];
int z = 1, k = 0, s;
void rec(int x, int y, int h)
{
	if (h > s)
	{
		return;
	}
	if (arr[x][y] == -1)
	{
		return;
	}
	if (arr[x][y] != 0)
	{
		if (arr[x][y] <= h)
		{
			return;
		}
		else
		{
			if (arr[x][y] % 2)
			{
				k--;
			}
			else z--;
			arr[x][y] = h;
			if (h % 2)
			{
				k++;
			}
			else
			{
				z++;
			}
		}
	}
	else if(x != 1500 || y != 1500)
	{
		arr[x][y] = h;
		if (h % 2)
		{
			k++;
		}
		else
		{
			z++;
		}
	}
	
	h++;
	if (h > s)
	{
		return;
	}
	if (y != 1500 || x != 1499)
		rec(x + 1, y, h);
	if (y != 1499 || x != 1500)
		rec(x, y + 1, h);
	if (x != 1501 || y != 1500)
		rec(x - 1, y, h);
	if (x != 1500 || y != 1501)
		rec(x, y - 1, h);
}
int main()
{
	int i, j, l, m, n, o, p;
	//1500
	cin >> n >> s;
	for (i = 0; i < n; i++)
	{
		cin >> o >> p;
		arr[o + 1500][p + 1500] = -1;
	}
	arr[1500][1500] = -2;
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(1500, 1500), 0));
	while (q.size())
	{
		pair<pair<int, int>, int>pr;
		pr = q.front();
		q.pop();
		arr[pr.first.first][pr.first.second] = pr.second;
		if (arr[pr.first.first - 1][pr.first.second] != -1 && arr[pr.first.first - 1][pr.first.second] != -2)
		{
			if (arr[pr.first.first - 1][pr.first.second] == 0)
				q.push(make_pair(make_pair(pr.first.first - 1, pr.first.second), pr.second + 1));
			else
			{
				if (arr[pr.first.first - 1][pr.first.second] > pr.second + 1)
				{

				}
			}
		}
	}

	return 0;
}