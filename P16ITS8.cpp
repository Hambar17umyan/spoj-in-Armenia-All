#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int b16i(char a)
{
	if (a <= '9' && a >= '0')
		return a - '0';
	return 10 + a - 'A';
}
string to2(int n, bool b)
{
	string res = "";
	while (n > 0)
	{
		char c = n % 2 + '0';
		res += c;
		n /= 2;
	}
	int k = res.size();
	if(b)
	for (int i = 0; i < 4 - k; i++)
	{
		res += '0';
	}
	reverse(res.begin(), res.end());
	return res;
}
string b16_b2(string s)
{
	string res = "";
	int i, j, m, n;
	for (i = 0; i < s.size(); i++)
	{
		n = b16i(s[i]);
		string s1 = to2(n, i != 0);
		for (j = 0; j < s1.size(); j++)
		{
			res += s1[j];
		}
	}
	return res;
}

string b2_b8(string s)
{
	string res = "";
	int k = s.size();
	for (int i = s.size() - 1; i >= 2; i -= 3)
	{
		k = i - 2;
		int a, b, c;
		a = s[i] - '0';
		b = s[i - 1] - '0';
		c = s[i - 2] - '0';
		int n = 0;
		n += a * 1;
		n += b * 2;
		n += c * 4;
		char cr = n;
		cr += '0';
		res += cr;
	}
	if (k == 2)
	{
		int a, b;
		a = s[1] - '0';
		b = s[0] - '0';
		int n = 0;
		n += a * 1;
		n += b * 2;
		char cr = n;
		cr += '0';
		res += cr;
	}
	else if (k == 1)
	{
		int a;
		a = s[0] - '0';
		int n = 0;
		n += a * 1;
		char cr = n;
		cr += '0';
		res += cr;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int i, j, k, m, n;
	string s;
	cin >> s;
	string b2 = b16_b2(s);
	cout << b2_b8(b2);

	return 0;
}