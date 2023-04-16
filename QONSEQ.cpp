#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

const int N = 100005;
ll arr[N];
ll a1[N], a0[N];
bool b[N];
int main()
{
	int i, j, n, m;
	cin >> n;
	ll k = 0, k0 = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	while (m--)
	{
		short op;
		cin >> op;
		if (op == 1)
		{
			int ind;
			cin >> ind;
			ind--;
			b[ind] = true;
			a0[ind] = k0 - a1[ind];
		}
		else if (op == 2)
		{
			int ind;
			cin >> ind;
			ind--;
			b[ind] = false;
			a1[ind] = k - a0[ind];
		}
		else if (op == 3)
		{
			int x;
			cin >> x;
			k += x;
			k0 += x;
		}
		else
		{
			cin >> i;
			i--;
			if (!b[i])
			{
				cout << arr[i] + a1[i] << endl;
			}
			else
			{
				cout << k - a0[i] + arr[i] << endl;
			}
		}
	}

	return 0;
}