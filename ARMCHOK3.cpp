#include <iostream>
#include <set>
#include <iterator>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

#define ll long long
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll arr[5002];
int main()
{
	ll i, j, k, m, n, o, p, l;
	string s;
	//speed;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ll res = 1;
	l = 1;	
	ll mn = arr[0], mx = arr[0];
	ll mn1 = -1, mx1 = -1;
	set<ll>st;
	for (i = 0; i < n; i++)
	{
		st.insert(arr[i]);
		if (i > 0)
		{
			st.erase(arr[i - 1]);
		}
		for (j = max(l, i + 1); j < n; j++)
		{
			if (arr[j] > mx)
				mx = arr[j];
			if (arr[j] < mn)
				mn = arr[j];
			k = st.size();
			st.insert(arr[j]);
			if (st.size() == k)
			{
				l = j - 1;
				break;
			}
			if (mx - mn + 1 == j - i + 1)
			{
				res = max(res, j - i + 1);
			}
		}
	}
	cout << res;

	return 0;
}