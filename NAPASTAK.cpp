#include <iostream>
#include <map>
using namespace std;

char lt(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 32;
	}
	return c;
}
int main()
{
	int i, j, k, l, m, n, o, p;
	string s;
	cin >> s;
	n = s.size();
	map<char, int>mp;
	for (i = 0; i < n; i++)
	{
		s[i] = lt(s[i]);
		mp[lt(s[i])]++;
	}
	//cout << s;
	string a = "RABBIT";
	int mn = 1025;
	for (i = 0; i < 6; i++)
	{
		if (a[i] == 'B')
		{
			if (mp[a[i]] / 2 < mn)
			{
				mn = mp[a[i]] / 2;
			}
			continue;
		}
		if (mp[a[i]] < mn)
		{
			mn = mp[a[i]];
		}
	}
	cout << mn;

	return 0;
}