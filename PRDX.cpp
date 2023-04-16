#include <iostream>
using namespace std;

int in[100002], ban[100002];
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n;
	int sumi = 0, sumb = 0;
	for (i = 0; i < n; i++)
	{
		cin >> in[i];
		sumi += in[i];
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> ban[i];
		sumb += ban[i];
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (n * (sumi - in[i]) > (n - 1) * sumi && m * (sumb + in[i]) > (m + 1) * sumb)
		{
			sum++;
		}
	}
	cout << sum;

	return 0;
}