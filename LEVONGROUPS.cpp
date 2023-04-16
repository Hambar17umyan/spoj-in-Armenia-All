#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int>dp[1005];
pair<int, int> arr[1005];
int main()
{
	int n, m;
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		arr[i] = { k, i };
		dp[k].push_back(i);
	}

	return 0;
}