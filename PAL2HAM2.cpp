#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

string to2(int n)
{
	string r = "";
	while (n)
	{
		r += ((n % 2) + '0');
		n /= 2;
	}
	reverse(r.begin(), r.end());
	return r;
}
int to10(string s)
{
	int i;
	int r = 0;
	int k = 1;
	if (s[s.size() - 1] == '1')
	{
		r++;
	}
	for (i = s.size() - 2; i >= 0; i--)
	{
		k *= 2;
		if (s[i] == '1')
			r += k;
	}
	return r;
}
int main()
{
	int i, j, n;
	cin >> n;
	int k = 0;
	if (n == 1)
	{
		cout << 1;
	}
	else if (n == 2)
	{
		cout << 3;
	}
	else if (n == 3)
	{
		cout << 5;
	}
	else if (n == 4)
	{
		cout << 7;
	}
	else
	{
		n -= 4;
		for (i = 4; ; i++)
		{
			k = (1 << (i / 2 + i % 2 - 1));
			if (n > k)
				n -= k;
			else
			{
				k += n - 1;
				string s = to2(k);
				//cout << to2(k) << endl;
				int y = s.size() - 1;
				if (i % 2 == 0)
				{
					s += s[y];
				}
				for (i = y - 1; i >= 0; i--)
				{
					s += s[i];
				}
				cout << to10(s) << endl;
				break;
			}
		}
	}

	return 0;
}