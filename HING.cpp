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

/////////////////////////////////////////////////////////////////////////////////////

int arr[7];
int arr1[7];
int arr2[7];
/*struct tp {
	int a, b, c;
};
bool operator ==(tp& a, tp& b)
{
	int a1[5], a2[5];
	a1[0] = a.a;
	a1[1] = a.b;
	a1[2] = a.c;
	a2[0] = b.a;
	a2[1] = b.b;
	a2[2] = b.c;
	sort(a1, a1 + 3);
	sort(a2, a2 + 3);
	if (a1[0] == a2[0] && a1[1] == a2[1] && a1[2] == a2[2])
	{
		return true;
	}
	else return false;
}
bool operator <(tp& a, tp& b)
{
	if (a.a < b.a)
		return true;
	return false;
}*/
void body()
{
	commadig(9);
	ll i, j, k, l, m, n, o, p;
	n = 5;
	ll sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}
	sort(arr, arr + n);
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	set<ll>st;
	do
	{
		int a, b, c, d, e;
		a = arr[0];
		b = arr[1];
		c = arr[2];
		d = arr[3];
		e = arr[4];
		if (a == 0)
			continue;
		do
		{
			int a1, b1, c1, d1, e1;
			a1 = arr1[0];
			b1 = arr1[1];
			c1 = arr1[2];
			d1 = arr1[3];
			e1 = arr1[4];
			if (a1 == 0)
				continue;
			do
			{
				int a2, b2, c2, d2, e2;
				a2 = arr2[0];
				b2 = arr2[1];
				c2 = arr2[2];
				d2 = arr2[3];
				e2 = arr2[4];
				if (a2 == 0)
					continue;
				int x, y, z, t;
				x = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
				y = a1 * 10000 + b1 * 1000 + c1 * 100 + d1 * 10 + e1;
				z = a2 * 10000 + b2 * 1000 + c2 * 100 + d2 * 10 + e2;
				t = x + y + z;
				//cout << x << ' ' << y << ' ' << z << ' ' << t << '\n';
				int m1, m2, m3, m4, m5;
				m1 = t / 10000;
				m2 = t / 1000;
				m2 -= 10 * m1;
				m3 = t / 100;
				m3 -= m1 * 100 + m2 * 10;
				m4 = t / 10;
				m4 -= m1 * 1000 + m2 * 100 + m3 * 10;
				m5 = t % 10;
				/*cout << m1 << ' ' << m2 << ' ' << m3 << ' ' << m4 << ' ' << m5;
				return;*/
				bool bl1 = false, bl2 = false, bl3 = false, bl4 = false, bl5 = false;
				for (i = 0; i < n; i++)
				{
					if (m1 == arr[i] && !bl1)
					{
						bl1 = true;
					}
					else if (m2 == arr[i] && !bl2)
					{
						bl2 = true;
					}
					else if (m3 == arr[i] && !bl3)
					{
						bl3 = true;
					}
					else if (m4 == arr[i] && !bl4)
					{
						bl4 = true;
					}
					else if (m5 == arr[i] && !bl5)
					{
						bl5 = true;
					}
				}
				if (x == y || x == z || x == t || y == z || y == t || z == t)
				{
					continue;
				}
				ll k1, k2, k3, k4, k5, k6;
				k1 = x * 10000000000;
				k1 += y * 100000;
				k1 += z;
				k2 = x * 10000000000;
				k2 += z * 100000;
				k2 += y;
				k3 = y * 10000000000;
				k3 += x * 100000;
				k3 += z;
				k4 = y * 10000000000;
				k4 += z * 100000;
				k4 += x;
				k5 = z * 10000000000;
				k5 += y * 100000;
				k5 += x;
				k6 = z * 10000000000;
				k6 += x * 100000;
				k6 += y;
				if (bl1 && bl2 && bl3 && bl4 && bl5)
				{
					o = st.size();
					st.insert(k1);
					st.insert(k2);
					st.insert(k3);
					st.insert(k4);
					st.insert(k5);
					st.insert(k6);
					if (o < st.size())
					{
						sum++;
						//cout << x << ' ' << y << ' ' << z << ' ' << t << endl;
					}
				}
			} while (next_permutation(arr2, arr2 + n));
		} 
		while (next_permutation(arr1, arr1 + n));
	} while (next_permutation(arr, arr + n));
	cout << sum;
}

RUN sol_status solved
