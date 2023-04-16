#include <iostream>
using namespace std;

int arr[1002];
int dp[1002][1002];
int rec(int l, int r)
{
	if (dp[l][r] + 1)
	{
		return dp[l][r];
	}
	if (l == r - 1)
	{
		return dp[l][r] = max(arr[l], arr[r]);
	}
	if (arr[l + 1] >= arr[r])
	{
		dp[l][r] = arr[l] + rec(l + 2, r);
	}
	else
	{
		dp[l][r] = arr[l] + rec(l + 1, r - 1);
	}

	if (arr[r - 1] > arr[l])
	{
		dp[l][r] = max(dp[l][r], arr[r] + rec(l, r - 2));
	}
	else
	{
		dp[l][r] = max(dp[l][r], arr[r] + rec(l + 1, r - 1));
	}
	return dp[l][r];
}
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		for (j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << rec(0, n - 1);

	return 0;
}