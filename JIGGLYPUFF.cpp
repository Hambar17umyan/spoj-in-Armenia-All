#include <iostream>
#include <string>
#include <map>
using namespace std;

char up(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return c;
}
int main()
{
	int i, j, k, l, m, n, o, p;
	string a;
	cin >> n;
	cin >> a;
	map<char, int>mp;
	int J = 0, I = 0, G = 0, L = 0, Y = 0, P = 0, F = 0;
	int res = 0;
	string s = "";
	for (i = 0; i < n; i++)
	{
		char ch;
		ch = up(a[i]);
		mp[ch]++;
		//cout << ch;
		if (!res && mp['J'] >= 1 && mp['I'] >= 1 && mp['G'] >= 2 && mp['Y'] >= 1 && mp['P'] >= 1 && mp['F'] >= 2 && mp['U'] >= 1 && mp['L'] >= 1)
		{
			res = i + 1;
			s += a[i];
		}
		else if(!res)
		{
			s += a[i];
		}
	}
	cout << res << '\n' << s;

	return 0;
}