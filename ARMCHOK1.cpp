#include <iostream>
#include <set>
#define ll long long
using namespace std;

ll arr[5004];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ll mx = 1;
	m = 0;
	k = 100000000000;
	for (i = 0; i < n; i++)
	{
		set<ll>st;
		st.insert(arr[i]);
		m = arr[i];
		k = arr[i];
		for (j = i + 1; j < n; j++)
		{
			st.insert(arr[j]);
			if (arr[j] > m)
				m = arr[j];
			if (arr[j] < k)
				k = arr[j];
			if (st.size() == j - i + 1 && m - k + 1 == st.size())
			{
				if (j - i + 1 > mx)
					mx = st.size();
			}
		}
	}
	cout << mx;

	return 0;
}