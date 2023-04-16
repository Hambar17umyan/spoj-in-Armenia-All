#include <iostream>
#include <math.h>
using namespace std;

int mn(int a, int b, int c, int d)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	if (d < a)
		a = d;
//	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	return a;
}

int main()
{
	int a, b, x, y;
	int i, j, k, l, m, n, o, p;
	cin >> a >> b;
	cin >> x >> y;
	//(0, 0), (a, 0), (a, b), (0, b)
	cout << mn(abs(a-x), abs(b-y), x, y);

	return 0;
}