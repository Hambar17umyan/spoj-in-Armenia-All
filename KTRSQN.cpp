#include <iostream>
using namespace std;
typedef long long ll;

const int N = 110;
ll dp[N][N];
pair<ll, ll>pref[N][N];//k, z
int main()
{
	int i, j, n, k;
	ll res = 0;
	cin >> k >> n;
	for (j = 1; j <= n; j++)
	{
		dp[1][j] = 1;
		if (j % 2 == 0)
		{
			pref[1][j] = pref[1][j - 1];
			pref[1][j].second++;
		}
		else
		{
			pref[1][j] = pref[1][j - 1];
			pref[1][j].first++;
		}
	}
	for (i = 2; i <= k; i++)
	{
		res = 0;
		for (j = 1; j <= n; j++)
		{
			if (j % 2 == 0)
			{
				pref[i][j] = pref[i][j - 1];
				dp[i][j] = pref[i - 1][j - 1].first;
				pref[i][j].second += dp[i][j];
			}
			else
			{
				pref[i][j] = pref[i][j - 1];
				dp[i][j] = pref[i - 1][j - 1].second;
				pref[i][j].first += dp[i][j];
			}
		}
	}
	cout << pref[k][n].first + pref[k][n].second << endl;
	
	return 0;
}