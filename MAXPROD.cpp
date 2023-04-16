#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define ll long long

short a[100005];
int pref[100005];

ll fastmod(ll a, ll b, ll mod) 
{
	ll ans = 1;
	while (b) 
	{
		if ((b & 1) == 1) 
		{
			ans *= a;
			ans %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
	}
	return ans;
}

int main()
{
	int i, j, k, n;
	cin >> n;
	k = 0;
	bool b = true;
	queue<int>zer;
	int res = -2;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (res < a[i])
			res = a[i];
		if (a[i] == 0)
		{
			zer.push(i);
			k = 0;
			b = true;
			continue;
		}
		if (a[i] == -2)
		{
			b = !b;
			k++;
		}
		else if(a[i]==2)
		{
			k++;
		}
		if (a[i] == -1)
			b = !b;
		if (b)
			pref[i] = k;
		else pref[i] = -k;
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		if (abs(a[i]) != 1)
		{
			k = 0;
			continue;
		}
		if (a[i] == -1)
		{
			if (k == 0)
			{
				k = -1;
			}
			else
			{
				res = max(res, 1);
				break;
			}
		}
		else
		{
			res = max(res, 1);
			break;
		}
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		if (abs(a[i]) == 0)
		{
			k = 0;
			continue;
		}
		if (a[i] == -1)
		{
			if (k == 0)
			{
				k = -1;
			}
			else
			{
				k *= -1;
			}
		}
		else if (a[i] == 2)
		{
			res = max(res, 2);
			break;
		}
		else if (a[i] == -2)
		{
			if (k < 0)
			{
				res = max(res, 2);
				break;
			}
			else if (k == 0)
				k = -2;
			else k *= -2;
		}
	}
	//cout << res << endl;
	if (zer.size() == n)
	{
		cout << 0 << endl;
		return 0;
	}
	zer.push(n);
	ll mod = 1000000007;
	int y = -1;
	//cout << res << endl;
	/*for (i = 0; i < n; i++)
		cout << pref[i] << ' ';
	cout << endl;*/
	int uu = res;
	res = -3;
	while (!zer.empty())
	{
		int x = 0;
		int r = zer.front();
		zer.pop();
		if (y + 1 == r)
		{
			y = r;
			continue;
		}
		x = pref[r - 1];
		if (x > 0)
		{
			res = max(pref[r - 1], res);
			//cout << res << endl;
		}
		else if (x < 0)
		{
			if (r - 2 == y)
			{
				y = r;
				continue;
			}
			k = 0;
			for (i = y + 1; i < r; i++)
			{
				if (a[i] < 0)
				{
					if (a[i] == -2)
						k++;
					break;
				}
				if (a[i] == 2)
					k++;
			}
			int l = 0;
			for (i = r - 1; i > y; i--)
			{
				if (a[i] < 0)
				{
					if (a[i] == -2)
						l++;
					break;
				}
				if (a[i] == 2)
					l++;
			}
			res = max(abs(x) - min(k, l), res);
			//cout << res << endl;
		}
		y = r;
	}
	if (res == -3)
	{
		cout << uu;
		return 0;
	}
	if (res == 0)
	{
		cout << uu << endl;
		return 0;
	}
	cout << fastmod(2, res, mod);

	return 0;
}