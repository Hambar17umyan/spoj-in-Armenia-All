#include<iostream>
#include<math.h>
#define ll long long

using namespace std;

bool prime(ll a)
{
	if (a <= 1)
		return 0;
	for (ll i = 2; i <= a/2; i++)
	{
		if (!(a % i))
			return 0;
	}
	return true;
}
bool arr[500002];
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n >> k;
	ll sum = 0;
	for (i = 0; i < k; i++)
	{
		ll a;
		cin >> a;
		arr[i] = prime(a);
		sum += arr[i];
	}
	ll mx = 0;
	mx = sum;
	for (i = k; i < n; i++)
	{
		cin >> m;
		arr[i] = prime(m);
		sum -= arr[i - k];
		sum += arr[i];
		if (mx < sum)
			mx = sum;
	}
	cout << mx;

	return 0;
}