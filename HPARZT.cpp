#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const int N = 1000008;
bool arr[N];
const int PRIME = 78505;
ll prime[PRIME];
ll k = 0;
void presolve()
{
	ll i, n, j;
	n = 1000005;
	for (i = 2; i < n; i++)
	{
		if (arr[i])
			continue;
		else
		{
			prime[k] = i;
			k++;
			for (j = i * 2; j < n; j += i)
			{
				arr[j] = true;
			}
		}
	}
}

void solve()
{
	ll n, i, j, m;
	cin >> n;
	set<ll>st;
	int res = 0;
	m = 0;
	set<ll>::iterator it;
	for (i = 0; i < k; i++)
	{
		if (n == prime[i])
		{
			res++;
			break;
		}
		if (n < prime[i])
		{
			break;
		}
		m += prime[i];
		st.insert(m);
		if (m < n)
		{
			continue;
		}
		if (m == n)
		{
			res++;
			continue;
		}
		it = st.find(m - n);
		if (it != st.end())
		{
			res++;
		}
	}
	cout << res << endl;
}

int main()
{
	presolve();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}