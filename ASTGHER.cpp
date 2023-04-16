#include <iostream>
#include <math.h>
using namespace std;

bool arr[102][102]; 
struct point
{
	bool f = 0, s = 0;
};
point pt[102][102];
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = (c=='*');
			if (c == '*')
			{
				k++;
			}
		}
		sum += k * (k - 1) * (k - 2);
	}
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < n; j++)
		{
			if (arr[j][i])
			{
				k++;
			}
		}
		sum += k * (k - 1) * (k - 2);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!pt[i][j].f)
			{
				k = 0;
				int x = i, y = j;
				for (x = i, y = j; x < n && y < n; x++, y++)
				{
					k += arr[x][y];
					pt[x][y].f = true;
				}
				for (x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
				{
					k += arr[x][y];
					pt[x][y].f = true;
				}
				sum += k * (k - 1) * (k - 2);
			}
			else if (!pt[i][j].s)
			{
				k = 0;
				int x = i, y = j;
				for (x = i, y = j; x < n && y >= 0; x++, y--)
				{
					k += arr[x][y];

					pt[x][y].s = true;
				}
				for (x = i - 1, y = j + 1; x >= 0 && y < n; x--, y++)
				{
					k += arr[x][y];
					pt[x][y].s = true;
				}
				sum += k * (k - 1) * (k - 2);
			}
		}
	}
	cout << sum / 6;

	return 0;
}
//101
//1001
//1101
//1100
//18=10010