#include <iostream>
#include <algorithm>
#define inf 1000000
using namespace std;

struct type {
	int first, second;
};
type arr[3336];
bool operator<(type& a, type& b)
{
	if (a.first < b.first)
		return true;
	if (a.first > b.first)
		return false;
	return a.second < b.second;
}
int main()
{
	int n;
	cin >> n;
	n /= 6;
	for (int i = 0; i < n; i++)
	{
		int a[8];
		for (int j = 0; j < 6; j++)
		{
			cin >> a[j];
		}
		arr[i].first = inf;
		arr[i].second = i;
		do {
			int k = abs((a[0] * 100 + a[1] * 10 + a[2]) - (a[3] * 100 + a[4] * 10 + a[5]));
			arr[i].first = min(arr[i].first, k);
		} while (next_permutation(a, a + 6));
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].second + 1 << ' ';
	}

	return 0;
}