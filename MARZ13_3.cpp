#include <iostream>
using namespace std;
typedef long long ll;


ll dp[68][68];
int main()
{
	ll i, j, n;
	cin >> n;
	n *= 2;
	dp[2][1] = 1;
	for (j = 2; j <= n; j++)
	{
		for (i = 1; i <= n + 1; i++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];
		}
	}
	cout << dp[1][n];

	return 0;
}