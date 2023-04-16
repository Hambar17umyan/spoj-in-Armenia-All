#include <iostream>
#define ll long long
using namespace std;
string rev(string a)
{
	int i, n = a.size();
	string ret = "";
	for (i = n - 1; i >= 0; i--)
	{
		ret += a[i];
	}
	return ret;
}

string solve(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		if (c == '1')
			c = '5';
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}

	return rev(r);
}

int main()
{
	ll a;
	cin >> a;
	cout << solve(a - 1);

	return 0;
}