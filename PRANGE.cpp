#include <iostream>
using namespace std;

bool p[10000007];
int pnum[10000007];
void find()
{
	for (int i = 2; i <= 10000000; i++)
		p[i] = true;
	for (int i = 2; i <= 10000000; i++)
	{
		if (!p[i])
		{
			continue;
		}
		for (int j = i; j <= 10000000; j += i)
		{
			p[j] = false;
		}
		p[i] = true;
	}
	for (int i = 1; i <= 10000000; i++)
	{
		pnum[i] = p[i] + pnum[i - 1];
	}
}
int main()
{
	int n, i, j;
	cin >> n;
	find();
	while (n--)
	{
		cin >> i >> j;
		cout << pnum[j] - pnum[i - 1] << endl;
	}

	return 0;
}