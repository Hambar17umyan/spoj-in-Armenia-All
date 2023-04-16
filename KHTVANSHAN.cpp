#include <iostream>
using namespace std;

int main()
{
	int i, j, k, l, m, n, o, p;
	string s1, s2, s;
	string res = "";
	cin >> s;
	n = s.size();
	cin >> m;
	k = n - m;
	o = 0;
	int ind = 0;
	while (o<k)
	{
		char mx = 0;
		for (i = ind; i < n; i++)
		{
			if (s[i] > mx)
			{
				mx = s[i];
				ind = i;
			}
		}
	}

	return 0;
}