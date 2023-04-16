#include <iostream>
using namespace std;

int main()
{
	int i, j, n, k;
	string s;
	cin >> s;
	n = s.size();
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << (s[0] != s[1]) << endl;
		return 0;
	}
	int res = n;
	for (i = 0; i < n; i++)
	{
		int y = i;
		for (j = i, k = n - 1; j < k; j++, k--)
		{
			y += (s[j] != s[k]);
		}
		res = min(res, y);
		//cout << i << ' ' << res << endl;
	}
	cout << res;

	return 0;
}