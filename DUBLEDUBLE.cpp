#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

string to2(ll a, int k)
{
	string s = "";
	while (a)
	{
		if (a % 2 == 1)
			s += '4';
		else s += '2';
		a /= 2;
	}
	int m = s.size();
	for (int i = 0; i < k - m; i++)
		s += "2";
	reverse(s.begin(), s.end());
	return s;
}
int main()
{
	ll i, j, n;
	cin >> n;
	string numb = to_string(n);
	for (i = 1; i <= numb.size(); i++)
	{
		for (j = 0; j < (1 << i); j++)
		{
			string s = to2(j, i);
			ll r = stoll(s);
			if (n % r == 0)
				cout << r << endl;
		}
	}


	return 0;
}