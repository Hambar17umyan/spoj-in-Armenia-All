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
		if (a % i == 0 || b % i == 0)
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
string lltos(ll l);
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

/////////////////////////////////////////////////////////////////////////////////////
bool stfnl(set<string> st, string a)
{
	if (st.find(a) == st.end())
	{
		return false;
	}
	return true;
}

char lat[6] = {'A', 'C', 'T', 'G'};
int fn(string s, string t)
{
	int n = s.size();
	int m = t.size();
	int ans = 0, i, j;
	//1
	for (i = 0; i < m; i++)
	{
		if (t[i] == s[0])
		{
			bool local = 1;
			for (j = 0; j < n; j++)
			{
				if (t[i + j] != s[j])
				{
					local = 0;
					break;
				}
			}
			if (local)
				ans++;
		}
	}
	return ans;
}

void body()
{
	commadig(9);
	int i, j, k, l, m, n, o, p;
	string s, t;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	cin >> s >> t;
	n = s.size();
	m = t.size();
	//1
	ans1 = fn(s, t);
	cout << ans1 << ' ';
	//2

	set<string>st1;
	for (i = 0; i < n; i++)
	{
		string ls = "";
		ls += s.substr(0, i) + s.substr(i + 1, n - i - 1);
		if (stfnl(st1, ls))
		{
			continue;
		}
		ans2 += fn(ls, t);
		st1.insert(ls);
	}
	cout << ans2 << ' ';
	//3
	set<string>st;
	for (i = 0; i < 4; i++)
	{
		char c = lat[i];
		for (j = 0; j <= n; j++)
		{
			string ls = "";
			ls += s.substr(0, j) + c + s.substr(j, n - j);
			//cout << ls << endl;
			if (stfnl(st, ls))
			{
				continue;
			}
			ans3 += fn(ls, t);
			st.insert(ls);
		}
	}
	cout << ans3;
	
}

RUN sol_status solved
