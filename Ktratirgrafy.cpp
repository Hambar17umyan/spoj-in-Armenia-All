#include <iostream>
using namespace std;

bool team[1005];
int main()
{
	int i, j, k, m, n;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		team[i] = ((i - 1) / k) % 2;
	}


	return 0;
}