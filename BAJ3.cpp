/*
							  Regional level of Armenian Republican Olympiad of Informatics 2021/22

														Sergey Hambardzumyan
													  Physmath school 9th grade
														Teacher - Andreasyan
*/
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
#define ll long long
#define usg unsigned
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define RUN int main(){speed; body(); return 0;}
#define RUN_WT int main(){speed; int t; cin>>t; while(t--)body(); return 0;}
#define commadig cout << fixed << setprecision //iomanip
#define sol_status
#define solved
#define time_limit
#define wrong_answer
#define memory_limit
#define compilation_error
#define not_sent
struct point
{
	int x, y;
};
//////////////////////////////////////////////////////////////////////////////////////
//functions
ll gcd(ll a, ll b)
{
	for (ll i = min(a, b); i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
}
ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}
bool pol(string a)
{
	int i, j;
	for (i = 0, j = a.size() - 1; i <= j; i++, j--)
	{
		if (a[i] != a[j])
		{
			return false;
		}
	}
	return true;
}
string rev(string a)
{
	int i, n = a.size();
	string ret = "";
	for (i = n - 1; i >= 0; i--)
	{
		ret += a[i];
	}
	return ret;
}
ll to2(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	return stoll(rev(r));
}
string to2_string(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}

	return rev(r);
}
void yn(bool b)
{
	if (b)
		cout << "YES\n";
	else cout << "NO\n";
}
bool stfn(set<int> st, int a)
{
	if (st.find(a) == st.end())
	{
		return false;
	}
	return true;
}
int vcfn(vector<int> v, int a)
{
	vector<int>::iterator it;
	it = find(v.begin(), v.end(), a);
	if (it != v.end())
	{
		return *it;
	}
	return -1;
}
string lltos(ll l)
{
	ll i, j;
	string ret = "";
	for (i = l; i > 0; )
	{
		ll k = l % 10;
		char c = k + 48;
		ret += c;
		l /= 10;
		if (l <= 0)
		{
			break;
		}
	}
	return rev(ret);
}
bool prime(ll a)
{
	ll i, j;
	for (i = sqrt(a); i > 1; i--)
	{
		if (!(a % i))
		{
			return false;
		}
	}
	return true;
}

ll s2tos10(ll a)
{
	string s = lltos(a);
	ll res = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		ll k = 0;
		if (s[i] == '1')
		{
			k = s.size() - 1 - i;
			res += pow(2, k);
		}
	}
	return res;
}


ll fact(ll a)
{
	ll i;
	ll res = 1;
	for (i = 2; i <= a; i++)
	{
		res *= i;
	}
	return res;
}

/////////////////////////////////////////////////////////////////////////////////////

int arr[5];
void body()
{
	commadig(9);
	int a, b, c;
	int i, j, k, l, m, n, o = 1000, p;
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	if (arr[0] % 3 == 0)
	{
		cout << arr[0];
		return;
	}
	if (arr[1] % 3 == 0)
	{
		cout << arr[1];
		return;
	}
	if (arr[2] % 3 == 0)
	{
		cout << arr[2];
		return;
	}
	if ((arr[0] * 2) % 3 == 0)
	{
		o = arr[0] * 11;
	}
	else if ((arr[1] * 2) % 3 == 0)
	{
		o = arr[1] * 11;
	}
	else if ((arr[2] * 2) % 3 == 0)
	{
		o = arr[2] * 11;
	}
	if ((arr[0] + arr[1]) % 3 == 0)
	{
		k = 10 * arr[0] + arr[1];
		cout << min(k, o);
		return;
	}
	if ((arr[0] + arr[2]) % 3 == 0)
	{
		k = 10 * arr[0] + arr[2];
		cout << min(k, o);
		return;
	}
	if ((arr[2] + arr[1]) % 3 == 0)
	{
		k = 10 * arr[1] + arr[2];
		cout << min(k, o);
		return;
	}
	if (o != 1000)
	{
		cout << o;
	}
	if ((arr[0] + arr[1] + arr[2]) % 3 == 0)
	{
		cout << min(100 * arr[0] + 10 * arr[1] + arr[2], arr[0] * 111);
		return;
	}
	cout << arr[0] * 111;
}

RUN sol_status not_sent
