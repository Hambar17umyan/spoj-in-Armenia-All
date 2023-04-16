#include <iostream>
#define ll long long
using namespace std;

ll dp[205][205];
int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}
	for (i = 0; i < n; i++)
		cin >> dp[i][i];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				dp[j][j + i] = max(dp[j][j + i], (dp[j][j + k] + dp[j + k + 1][j + i]) / 2);
			}
		}
	}
	cout << dp[0][n - 1];

	return 0;
}