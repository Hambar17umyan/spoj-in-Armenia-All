#include <iostream>
using namespace std;

bool am1[435][102], am2[102][102], am3[102][102], am4[102][102];
bool f[435][102];
#define sp system("Pause");
int main()
{
	int i, j, k, l, m, n, o, p;
	int n1, m1;
	cin >> n1 >> m1;
	int mn = 10005;
	int i1 = -1, j1;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
		{
			char c;
			cin >> c;
			if (c == '.')
			{
				f[i][j] = false;
			}
			else f[i][j] = true;
		}
	}
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '.')
			{
				am1[i][j] = false;
				am2[i][m - j - 1] = false;
				am3[n - i - 1][j] = false;
				am4[n - i - 1][m - j - 1] = false;
			}
			else
			{
				am1[i][j] = true;
				am2[i][m - j - 1] = true;
				am3[n - i - 1][j] = true;
				am4[n - i - 1][m - j - 1] = true;
			}
		}
	}
	sp
	for (i = 0; i <= n1 - n; i++)
	{
		for (j = 0; j <= m1 - m; j++)
		{
			int sum = 0;
			for (i1 = i; i1 < i + n; i1++)
			{
				for (j1 = j; j1 < j + m; j1++)
				{
					if (am1[i1 - i][j1 - j] || !f[i1][j1])
					{
						sum++;
					}
				}
			}
			if (mn > sum)
				mn = sum;
			sp
			sum = 0;
			for (i1 = i; i1 < i + n; i1++)
			{
				for (j1 = j; j1 < j + m; j1++)
				{
					if (am2[i1 - i][j1 - j] || !f[i1][j1])
					{
						sum++;
					}
				}
			}
			if (mn > sum)
				mn = sum;
			sp
			sum = 0;
			for (i1 = i; i1 < i + n; i1++)
			{
				for (j1 = j; j1 < j + m; j1++)
				{
					if (am3[i1 - i][j1 - j] || !f[i1][j1])
					{
						sum++;
					}
				}
			}
			if (mn > sum)
				mn = sum;
			sp
			sum = 0;
			for (i1 = i; i1 < i + n; i1++)
			{
				for (j1 = j; j1 < j + m; j1++)
				{
					if (am4[i1 - i][j1 - j] || !f[i1][j1])
					{
						sum++;
					}
				}
			}
			if (mn > sum)
				mn = sum;
			sp
		}
	}
	cout << mn;

	return 0;
}