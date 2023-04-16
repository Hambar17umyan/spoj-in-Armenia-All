#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
	int i, j, n;
	cin >> n;
	string s;
	cin >> s;

	ll res = 0;
	for (j = 0; j < s.size(); j++)
	{
		ll k = (s[j] - 'a');
		res += (k + 1);
		ll m = 1;
		if (k != 0)
		{
			for (i = j + 1; i < n; i++)
			{
				m *= 3;
				res += m * k;
			}
		}
	}
	cout << res << endl;

	return 0;
}