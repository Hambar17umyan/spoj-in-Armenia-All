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
bool eratosthenes[10000000];
int find_primes(ll s, ll f)
{
	eratosthenes[1] = true;
	ll count = 0;
	for (ll i = 2; i <= f; i++)
	{
		if (!eratosthenes[i])
		{
			if (i >= s)
				count++;
			ll k = f / i;
			for (ll j = 2; j <= k; j++)
			{
				eratosthenes[j * i] = true;
			}
		}
	}
	return count;
}

/////////////////////////////////////////////////////////////////////////////////////

char cf;
bool bf;
string work_wth_string(string s, ll ko, int io, int nl)
{
	ll n = s.size();
	ll i, j;
	string res = "";
	ll k = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'A')
		{
			res += "ABC";
			k += 3;
			if (io == nl - 1)
			{
				if (k > ko)
				{
					bf = true;
					if (k - ko == 0)
					{
						cf = 'C';
					}
					else if (k - ko == 1)
					{
						cf = 'B';
					}
					else cf = 'A';
				}
			}
		}
		else if (s[i] == 'B')
		{
			res += "CBA";
			k += 3;
			if (io == nl - 1)
			{
				if (k > ko)
				{
					bf = true;
					if (k - ko == 0)
					{
						cf = 'A';
					}
					else if (k - ko == 1)
					{
						cf = 'B';
					}
					else cf = 'C';
				}
			}
		}
	}
	return res;
}
void body(string s1, int n)
{
	commadig(9);
	ll i, j, k, l, m, o, p;
	cin >> k;
	string s = s1;
	p = s.size();
	if (n == 0)
	{
		cout << s << endl;
		return;
	}
	if (s == "C")
	{
		o = 1;
		s = "AB";
	}
	else o = 0;
	//cf = s[0];
	for (i = o; i < n; i++)
	{
		string s2;
		s2 = work_wth_string(s, k, i, n);
		s = s2;
		if (s.size() >= k)
		{
			cout << s[k - 1] << endl;
			return;
		}
	}
	cout << s[k - 1];
}

int main()
{
	speed;
	string c;
	int n, m;
	cin >> c >> n >> m;
	while (m--)
	{
		body(c, n);
	}
}
sol_status not_sent
