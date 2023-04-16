#include <iostream>
using namespace std;

int arr[1000006];
int ress[1000007];
pair<int, int>pref[1000007];
pair<int, int>suf[1000007];
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n;
	o = 0;
	p = 0;
	pref[0] = make_pair(0, 0);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == -1)
		{
			o++;
		}
		else if (arr[i] == 1)
		{
			p++;
		}
		pref[i + 1] = make_pair(o, p);
	}
	o = 0; 
	p = 0;
	suf[n] = make_pair(0, 0);
	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] == -1)
		{
			o++;
		}
		else if (arr[i] == 1)
		{
			p++;
		}
		suf[i] = make_pair(o, p);
	}
	for (i = 0; i <= n; i++)
	{
		
	}


	return 0;
}