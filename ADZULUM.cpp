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


char charabs(char a)
{
	if (a >= 'A' && a <= 'Z')
	{
		int k = 'a' - 'A';
		a += k;
	}
	return a;
}
int stfin(string s, string t)
{
	ll i, j;
	ll n, m;
	n = s.size();
	m = t.size();
	for (i = 0; i < m; i++)
	{
		if (charabs(t[i]) == charabs(s[0]))
		{
			bool b = true;
			for (j = 0; j < n; j++)
			{
				if (charabs(t[i + j]) != charabs(s[j]))
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				return i;
			}
		}
	}
	return -1;
}
void body()
{
	commadig(9);
	ll i, j, k, l, m, n, o, p;
	string s, t, res = "";
	cin >> s >> t;
	n = s.size();
	m = t.size();
	bool b = false;
	string s1 = s, s2 = t;
	s1 = s1 + t;
	s2 = s2 + s;
	if (s == t)
	{
		cout << s;
		return;
	}
	//s-t
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (n - i > m)
		{
			continue;
		}
		if (charabs(s[i]) == charabs(t[0]))
		{
			b = true;
			for (j = 0; i + j < n; j++)
			{
				if (charabs(s[i + j]) != charabs(t[j]))
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				s1 = "";
				for (j = 0; j < i; j++)
				{
					s1 += s[j];
				}
				for (j = 0; j < m; j++)
				{
					s1 += t[j];
				}
				break;
			}
		}
	}
	//t-s
	j = 0;
	for (i = 0; i < m; i++)
	{
		if (m - i > n)
		{
			continue;
		}
		if (charabs(s[0]) == charabs(t[i]))
		{
			b = true;
			for (j = 0; i + j < m; j++)
			{
				if (charabs(t[i + j]) != charabs(s[j]))
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				s2 = "";
				for (j = 0; j < i; j++)
				{
					s2 += t[j];
				}
				for (j = 0; j < n; j++)
				{
					s2 += s[j];
				}
				break;
			}
		}
	}
	if (s1.size() > s2.size())
	{
		cout << s2;
		return;
	}
	else if (s1.size() < s2.size())
	{
		cout << s1;
		return;
	}
	else if (s1.size() == s2.size())
	{
		for (i = 0; i < s1.size(); i++)
		{
			if (s1[i] < s2[i])
			{
				cout << s1;
				return;
			}
			else if (s2[i] < s1[i])
			{
				cout << s2;
				return;
			}
		}
		cout << s1;
	}
	else
	{
		cout << s1;
		return;
	}
}

RUN sol_status solved
