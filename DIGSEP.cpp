#include <iostream>
#include <string>
using namespace std;

long long stoll_(string a)
{
	long long res = 0;
	for (int i = 0; i < a.size(); i++)
	{
		res += a[i] - 48;
		res *= 10;
	}
	return res/10;
}
int main()
{
	string s;
	int i, j, k, l, n, o;
	long long m;
	cin >> s >> m;
	n = s.size();
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			string s1 = s.substr(0, i + 1);
			string s2 = s.substr(i + 1, j - i);
			string s3 = s.substr(j + 1, n - j - 1);
			if (stoll_(s1) + stoll_(s2) + stoll_(s3) == m)
			{
				cout << s1 << '+' << s2 << '+' << s3 << '\n';
				//cout<< stoll(s1) + stoll(s2) + stoll(s3) << '\n';
			}
		}
	}

	return 0;
}