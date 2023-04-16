#include <iostream>
using namespace std;

string arr[10];
bool b;
void f(int x, int y)
{
	int i, j;
	for (i = x + 1; i < 8; i++)
	{
		if (arr[i][y] == 'w')
			break;
		else if (arr[i][y] == 'b')
		{
			b = false;
			return;
		}
	}
	for (i = x - 1; i >=0; i--)
	{
		if (arr[i][y] == 'w')
			break;
		else if (arr[i][y] == 'b')
		{
			b = false;
			return;
		}
	}
	for (j = y + 1; j < 8; j++)
	{
		if (arr[x][j] == 'w')
			break;
		else if (arr[x][j] == 'b')
		{
			b = false;
			return;
		}
	}
	for (j = y - 1; j >= 0; j--)
	{
		if (arr[x][j] == 'w')
			break;
		else if (arr[x][j] == 'b')
		{
			b = false;
			return;
		}
	}
	for (i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
	{
		if (arr[i][j] == 'w')
			break;
		else if (arr[i][j] == 'b')
		{
			b = false;
			return;
		}
	}
	for (i = x + 1, j = y - 1; i < 8 && j >=0; i++, j--)
	{
		if (arr[i][j] == 'w')
			break;
		else if (arr[i][j] == 'b')
		{
			b = false;
			return;
		}
	}
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (arr[i][j] == 'w')
			break;
		else if (arr[i][j] == 'b')
		{
			b = false;
			return;
		}
	}
	for (i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (arr[i][j] == 'w')
			break;
		else if (arr[i][j] == 'b')
		{
			b = false;
			return;
		}
	}
}

int main()
{
	int i, j, k, l, m, n, o, p;
	for (i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	int res = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			b = true;
			if (arr[i][j] == '.')
			{
				f(i, j);
				if (b)
					res++;
			}
		}
	}
	cout << res;

	return 0;
}