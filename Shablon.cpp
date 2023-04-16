//Armenian school olympiads
//Yerevan Physmath School
//9th grade
//Sergey Hambardzumyan
//Teacher-Andreasyan
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <iterator>
#include <deque>
using namespace std;
#define ll long long
#define testing int main(){int t; cin>>t; while(t--){pwt();} return 0;}
#define no_tests int main(){pwt(); return 0;}
#define loop for(i=0; i<n; i++)
#define iarr for(i=0; i<n; i++){cin>>arr[i];}
#define oarr for(i=0; i<n; i++){cout<<arr[i]<<' ';}

int nod(int a, int b)
{
	for (int i = min(a, b); i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
			break;
		}
	}
}
ll nodll(ll a, ll b)
{
	for (ll i = min(a, b); i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
			break;
		}
	}
}

int nok(int a, int b)
{
	return (a * b) / nod(a, b);
}
ll nokll(ll a, ll b)
{
	return (a * b) / nodll(a, b);
}

vector<int> div(int a)
{
	vector<int> vc;
	for (int i = 1; i <= a / 2 + 1; i++)
	{
		if (a % i == 0)
		{
			vc.push_back(i);
		}
	}
	if (a != 1)
		vc.push_back(a);
	return vc;
}
vector<ll> divll(ll a)
{
	vector<ll> vc;
	for (ll i = 1; i <= a / 2 + 1; i++)
	{
		if (a % i == 0)
		{
			vc.push_back(i);
		}
	}
	if (a != 1)
		vc.push_back(a);
	return vc;
}

bool prime(int a)
{
	bool res = true;
	if (a < 4)
		res = true;
	else
	{
		for (int i = 2; i <= sqrt(a); i++)
		{
			res = !(a % i == 0);
		}
	}
	return res;
}
bool primell(ll a)
{
	bool res = true;
	if (a < 4)
		res = true;
	else
	{
		for (ll i = 2; i <= sqrt(a); i++)
		{
			res = !(a % i == 0);
		}
	}
	return res;
}
bool odd(int a)
{
	return a % 2 == 0;
}
void yn(bool b)
{
	if (b)
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}
bool fnd(string s, string mns)
{
	return (s.find(mns) != string::npos);
}

int fndi(int a, ll arr[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] == a)
		{
			return i;
		}
	}
	return -1;
}
char upper(char c)
{
	if (c >= 'a')
	{
		return c - 32;
	}
	return c;
}
char lower(char c)
{
	if (c < 'a')
	{
		return c + 32;
	}
	return c;
}
//////////////////////////////////////////////////////
int arr[200002];
void pwt()
{
	int i, j, k, l, m, n, o, p;
}

no_tests