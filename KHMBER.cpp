#include <iostream>
#include <queue>
using namespace std;

const int N = 500005;
int n;
int arr[N];
pair<int, int>suf[N];
int main()
{
	int i, j, k, m;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int mn, mx;
	mn = mx = arr[n - 1];
	suf[n - 1] = { mn, mx };
	for (i = n - 2; i >= 0; i--)
	{
		if (arr[i] == mx + 1)
		{
			mx++;
		}
		else if (arr[i] == mn - 1)
		{
			mn--;
		}
		else
		{
			break;
		}
		suf[i] = { mn, mx };
	}
	mn=mx=

	return 0;
}