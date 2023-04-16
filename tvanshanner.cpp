//#include <fstream>
/*#define fin ifstream cin
#define fon ofstream cout*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	long long i, j, k, l, m, n, o, p, x, y, z, res=0;
	cin >> n;
	m = 9;
	k = 1;
	while (true)
	{
		if (n >= m)
		{
			n -= m;
			res += k * m;
			k++;
			m = m * 10;
			//cout << n << ' ' << m << '\n';
		}
		else 
		{
			res += k * n;
			break;
		}
	}
	cout << res;

	return 0;
}

//link https://am.spoj.com/problems/TVANSHAN


/*ACT
ACTGACTG*/