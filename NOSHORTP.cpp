#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 100005, K = 25;
vector<int>g[N];
ll q[N][K];
bool color[N];
ll urec[K];

void rec(int ind, int k)
{
	for (int i = 0; i <= 22; i++)
	{
		urec[i] = 0;
	}
	color[ind] = true;
	int i;
	for (i = 0; i < g[ind].size(); i++)
	{
		if (!color[g[ind][i]])
		{
			rec(g[ind][i], k);
			for (int j = 0; j <= k + 1; j++)
			{
				urec[j] = q[g[ind][i]][j];
			}
		}

	}
}
int main()
{
	int i, j, k, n;
	cin >> n >> k;
	for (i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		q[a][0] = 1;
		q[b][0] = 1;
	}
	q[0][0] = 1;
	rec(1, k);
	ll res = 0;
	for (i = 1; i <= n; i++)
	{
		res += q[i][k + 1];
	}
	cout << res << endl;

	return 0;
}