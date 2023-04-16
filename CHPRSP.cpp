#include <iostream>
using namespace std;

const int N = 100003;
long long dp[N];
int main()
{
	int n;
	cin >> n;
	long long mod = 1000000007;
	dp[0] = 1;
	dp[1] = 5;
	dp[2] = 11;
	for (int i = 3; i < n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] * 4 + dp[i - 3] * 2;
		dp[i] %= mod;
	}
	cout << dp[n - 1];

	return 0;
}