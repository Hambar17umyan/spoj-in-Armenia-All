#include <iostream>
#include <algorithm>
using namespace std;

int arr[105];
int main()
{
	int n, l, i;
	cin >> l >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int res = 1;
	int k = arr[0] + 2 * l - 1;
	for(i=1; i<n; i++)
	{
		if (k < arr[i])
		{
			k = arr[i] + 2 * l - 1;
			res++;
		}
	}
	cout << res << endl;
	return 0;
}