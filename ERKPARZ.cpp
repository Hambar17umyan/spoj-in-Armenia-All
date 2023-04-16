#include <iostream>
using namespace std;

bool arr[40005];

void find(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
			continue;
		for (int j = i * 2; j <= n; j += i)
		{
			arr[j] = true;
		}
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	int res = 0;
	find(b);
	for (int i = 2; i <= b; i++)
	{
		cout << i << ' ' << arr[i] << endl;
	}
	for (int i = 2; i <= b; i++)
	{
		if (arr[i])
			continue;
		for (int j = i + 1; j <= b; j++)
		{
			if (arr[j])
				continue;
			if (a <= arr[i] + arr[j] && arr[i] + arr[j] <= b)
			{
				res++;
			}
		}
	}
	cout << res;

	return 0;
}