#include <iostream>
using namespace std;
typedef long long ll;

ll dp[33][12];
int main()
{
	ll i, j, n, k, m;
	cin >> n >> k;
	if (k == 1)
	{
		cout << n;
		return 0;
	}
	for (i = 0; i < k - 1; i++)
	{
		dp[i][0] = 1;
	}
	dp[i][0] = 0;
	
	for (i = 0; i < 10; i++)
		dp[0][i] = 1;
	for (i = 1; i < k; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (i == k - 1 && j == 1)
			{
				dp[i][j] = k;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	i = k - 1;
	j = 0;
	n--;
	while (i >= 0)
	{
		if (dp[i][j] <= n)
		{
			n -= dp[i][j];
			j++;
		}
		else
		{
			cout << j;
			j = 0;
			i--;
		}
	}

	return 0;
}