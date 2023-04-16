#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;

ll bq = 1;

vector<ll> prdiv(ll n)
{
    ll k;
    k = 0;
    vector<ll>res;
    while (n % 2 == 0)
    {
        k++;
        n = n / 2;
        res.push_back(2);
    }
    if (k != 0)
    {
        bq *= k + 1;
    }
    ll sq = sqrt(n);
    ll i;
    for (i = 3; i <= sq; i++)
    {
        k = 0;
        while (n % i == 0)
        {
            k++;
            n = n / i;
            res.push_back(i);
        }
        if (k != 0)
        {
            bq *= k + 1;
        }
    }

    if (n > 2)
    {
        res.push_back(n);
        bq *= 2;
    }
    return res;
}

vector<pair<ll, ll>>us;
map<ll, ll> dp[105];
int main()
{
    ll n, m, i, j;
    cin >> n >> m;
    vector<ll>d = prdiv(n);
    sort(d.begin(), d.end());
    set<pair<ll, ll>>st;
    dp[1][1] = 1;
    for (i = 0; i < d.size(); i++)
    {
        ll sv = us.size();
        for (j = sv - 1; j >= 0; j--)
        {
            if (us[j].first % d[i] == 0)
            {
                ll sz = st.size();
                st.insert(make_pair(d[i] * us[j].first, us[j].second));
                if (st.size() != sz)
                {
                    us.push_back(make_pair(d[i] * us[j].first, us[j].second));
                    dp[us[j].second][d[i] * us[j].first]++;
                    dp[1][d[i] * us[j].first] = 1;
                }
            }
            else
            {
                ll sz = st.size();
                st.insert(make_pair(d[i] * us[j].first, us[j].second + 1));
                if (st.size() != sz)
                {
                    us.push_back(make_pair(d[i] * us[j].first, us[j].second + 1));
                    dp[us[j].second + 1][d[i] * us[j].first]++;
                    dp[1][d[i] * us[j].first] = 1;
                }
            }
        }
        ll sz = st.size();
        st.insert(make_pair(d[i], 1));
        if (st.size() != sz)
        {
            us.push_back(make_pair(d[i], 1));
            dp[1][d[i]] = 1;
        }
    }
    ll k = 0;
    for (map<ll, ll>::iterator it = dp[1].begin(); it != dp[1].end(); it++)
    {
        for (i = 2; i <= m; i++)
        {
            dp[i][it->first] += dp[i - 1][it->first];
        }
        k += dp[m][it->first];
    }
    cout << k << endl;

    return 0;
}