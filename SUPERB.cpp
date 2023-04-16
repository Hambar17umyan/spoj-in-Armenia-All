#include <iostream>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long

vector<ll>p;

void find_prime()
{
	ll maximum = 31607;
	for (ll i = 2; i <= maximum; i++)
	{
		bool y = true;

		ll k = sqrt(i);
		for (ll j = 2; j <= k; j++)
		{
			if (i % j == 0)
			{
				y = false;
				break;
			}
		}
		if (y)
			p.push_back(i);
	}
}
int main()
{
	set<ll>s;
	ll k = 1;
	int i, j;
	cout<<
	find_prime();
	int n = p.size();
	for (i = 0; i < n; i++)
	{
		k = p[i];
		for (j = i + 1; j < n; j++)
		{
			k *= p[j];
			s.insert(k);
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		cin >> k;
		if (s.find(k) == s.end())
			cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}