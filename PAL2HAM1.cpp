#include <iostream>
#include <set>
#define ll long long
using namespace std;

set<ll> arr[35];
int main()
{
	int i, j, n;
	cin >> n;
	int k = 30;
	arr[0].insert(1);
	arr[1].insert(3);
	for (i = 2; i < k; i++)
	{
		arr[i].insert((1 << i) + 1);
		for (j = i - 2; j >= 0; j -= 2)
		{
			for (set<ll, ll>::iterator it = arr[j].begin(); it != arr[j].end(); it++)
			{
				arr[i].insert(((1 << i) + 1) + ((*it) << (i - j - 1)));
			}
		}
	}
	i = 0;
	while (n > 0)
	{
		if (n > arr[i].size())
		{
			n -= arr[i].size();
			i++;
		}
		else
		{
			j = 1;
			for (set<ll, ll>::iterator it = arr[i].begin(); it != arr[i].end(); it++)
			{
				if (j == n)
				{
					cout << *it;
					return 0;
				}
				j++;
			}
		}
	}

	return 0;
}