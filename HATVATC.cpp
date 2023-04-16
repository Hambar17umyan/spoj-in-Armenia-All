#include <iostream>
using namespace std;
typedef long long ll;

const int N = 20005;
struct dinamic {
	ll dd, da, ad, aa;
};
dinamic dp[N];//dd da ad aa
pair<ll, ll>arr[N];

int main()
{
	ll n, i, j;
	cin >> n;
	ll res = 0;
	arr[0] = make_pair(1, 1);
	arr[n + 1] = make_pair(n, n);
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		res += arr[i].second - arr[i].first;
	}
	res += n - 1;
	dp[0].dd = abs(arr[0].first - arr[1].first);
	dp[0].da = abs(arr[0].first - arr[1].second);
	dp[0].ad = abs(arr[0].second - arr[1].first);
	dp[0].aa = abs(arr[0].second - arr[1].second);
	for (i = 1; i <= n; i++)
	{
		dp[i].dd = abs(arr[i].first - arr[i + 1].first) + min(dp[i - 1].dd, dp[i - 1].ad);
		dp[i].da = abs(arr[i].first - arr[i + 1].second) + min(dp[i - 1].dd, dp[i - 1].ad);
		dp[i].ad = abs(arr[i].second - arr[i + 1].first) + min(dp[i - 1].da, dp[i - 1].aa);
		dp[i].aa = abs(arr[i].second - arr[i + 1].second) + min(dp[i - 1].da, dp[i - 1].aa);
	}
	for (i = 0; i <= n; i++)
		cout << dp[i].dd << ' ' << dp[i].da << ' ' << dp[i].ad << ' ' << dp[i].aa << endl;
	res += min(min(dp[n].aa, dp[n].ad), min(dp[n].dd, dp[n].da));
	cout << res << endl;

	return 0;
}