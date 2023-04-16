#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int arr[25];
int main()
{
	int i, j, k, l, m, n, o, p, x, y, z;
	double max = -1;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << setprecision(6);
	for (i = 0; i < n - 2; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				double a = arr[i];
				double b = arr[j];
				double c = arr[k];
				double pd2 = (a + b + c) / 2;
				double area =pd2 *(pd2 - a) * (pd2 - b) * (pd2 - c);
				if (area > max && a+b>c && a+c>b && b+c>a)
					max = area;
			}
		}
	}
	cout << sqrt(max);

	return 0;
}
/*

https://am.spoj.com/problems/BIG3ANK/

*/