#include <iostream>
using namespace std;

int res[100005];
int res1[100005];
int main()
{
	int n, i, j;
	int mn = 0;
	cin >> n;
	int k = 0;
	for (i = n - 1; i >= 0; i--)
	{
		k = n - i;
		mn /= 10;
		k += mn;
		res[i] = k % 10;
		mn = k - k % 10;
	}
	for (i = n - 2; i >= 0; i--)
	{
		k = i + 1;
		mn /= 10;
		k += mn;
		res1[i] = k % 10;
		mn = k - k % 10;
	}
	mn /= 10;
	if (mn != 0)
		cout << mn;
	for (i = 0; i < n - 1; i++)
		cout << res1[i];
	for (i = 0; i < n; i++)
		cout << res[i];

	return 0;
}