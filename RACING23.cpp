#include <iostream>
using namespace std;

int arr[200005];
int dp[200005];
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[1];
	dp[2] = arr[2];
	for (i = 3; i < n; i++)
	{
		dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
		dp[i] += arr[i];
	}
	int res = dp[n - 1];
	for (i = n - 2; i >= n - 3 && i >= 0; i--)
		res = min(res, dp[i]);
	cout << res << endl;

	return 0;
}
