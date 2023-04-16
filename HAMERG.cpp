#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long res = 4;
	if (n == 1)
	{
		cout << 2;
	}
	else if (n == 2)
		cout << 4;
	else
	{
		long long a, b;
		a = 2;
		b = 4;
		while (n > 2)
		{
			swap(a, b);
			b += a;
			n--;
		}
		cout << b;
	}

	return 0;
}