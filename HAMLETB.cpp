#include <iostream>
using namespace std;

struct bot
{
	int s, f;
};
bot arr[2004];
int tm[3004]; //time
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n;
	int res = 0;
	int mx = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].s >> arr[i].f;
		arr[i].f += arr[i].s;
		tm[arr[i].s]++;
		tm[arr[i].f]++;
		tm[arr[i].f + arr[i].f - arr[i].s]++;
		if (tm[arr[i].s] > mx)
			mx = tm[arr[i].s];
		if (tm[arr[i].f] > mx)
			mx = tm[arr[i].f];
		if (tm[arr[i].f + arr[i].f - arr[i].s] > mx)
			mx = tm[arr[i].f + arr[i].f - arr[i].s];
	}

	cout << mx / 2 + mx % 2;

	return 0;
}