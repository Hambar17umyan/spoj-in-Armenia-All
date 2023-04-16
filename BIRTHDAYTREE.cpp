#include <iostream>
using namespace std;

int min(int a, int b, int c, int d)//14 8 6 15
{
	if (b < a)//mn=8
		a = b;//a=8
	if (c < a)//mn=6
		a = c;//a=6
	if (d < a)//mn chi poxi
		a = d;

	return a;//mn=6
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min(a, b, c, d);

	return 0;
}