#include <iostream>
#define ll unsigned long long
using namespace std;

ll dp[102][102];
char op[102][102];
int main()
{
	ll i, j, k, l, m, n, o, p;
	string s;
	ll t;
	cin >> t;
	while (t--)
	{
		for (i = 0; i < 102; i++)//amen testi hamar datarkel dp masivnery
		{
			for (j = 0; j < 100; j++)
			{
				op[i][j] = '-';
				dp[i][j] = 0;
			}
		}
		cin >> s;
		n = s.size();
		o = 0;
		k = 0;
		char c;
		for (i = 0; i < n; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')//ete tvanshana 
			{
				k *= 10;
				k += (s[i] - 48);
			}
			else//ete operatora
			{
				dp[o][o] = k;//glxavor ankyunagci lracum
				k = 0;
				op[o][o] = s[i];
				o++;
			}
		}
		if (o == 0)//ete 1 hat tiv ka
		{
			cout << s << endl;
			continue;
		}
		dp[o][o] = k;
		op[o][o] = '-';
		n = o;
		o = 0;
		k = 1;
		for (i = 0; i <= n; i++)
		{
			for (j = i; j <= n; j++)
			{
				op[i][j] = op[j][j];
				//op[i][j]-> i-ic j maximal arjeqy vor gtnenq dranic heto inch gorcoxutyuna galis
				//1+2*3+4 i=0 j=2 depqum op[i][j]=+, i=0 j=1 depqum op[i][j]=*
			}
		}
		for (o = 0; o <= n; o++)
		{
			for (i = 0; i <= n; i++)
			{
				j = i + k;
				for (ll v = 0; v < j - i; v++)
				{
					l = dp[j - v][j];
					p = dp[i][j - v - 1];
					if (op[i][j - 1 - v] == '+')
					{
						l += p;
					}
					else l *= p;
					if (l > dp[i][j])
					{
						dp[i][j] = l;
					}
				}
			}
			k++;
		}
		cout << dp[0][n] << endl;
		/*for (i = 0; i <= n; i++)
		{
			for(j=0; j<=n; j++)
			cout << dp[i][j] << ' ';
			cout << endl;
		}*/
	}

	return 0;
}