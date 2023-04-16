#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b, i, j, k, l;
	cin >> n >> m >> a >> b;
	int p1, p2, p3, p4;
	p1 = (n - a) * (m - b);
	p2 = a * b;
	p3 = (n - a) * b;
	p4 = (m - b) * a;
	cout << max(max(p1, p2), max(p3, p4));

	return 0;
}