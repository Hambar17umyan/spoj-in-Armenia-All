#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int arr[100005];
int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int r = 1;
	for (i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
			r++;
	}

	int m;
	scanf("%d", &m);
	while (m--)
	{
		int k;
		scanf("%d", &i);
		scanf("%d", &k);
		i--;
		if (arr[i] == k)
		{
			printf("%d", r);
			printf("%c", '\n');
		}
		else
		{
			if (n == 1)
			{
				printf("1\n");
				continue;
			}
			if (i == 0)
			{
				if (arr[i + 1] == arr[i])
				{
					r++;
				}
				else if (k == arr[i + 1])
				{
					r--;
				}
				printf("%d", r);
				printf("%c", '\n');
			}
			else if (i == n - 1)
			{
				if (arr[i - 1] == arr[i])
				{
					r++;
				}
				else if (k == arr[i - 1])
				{
					r--;
				}
				printf("%d", r);
				printf("%c", '\n');
			}
			else
			{
				if (arr[i] == arr[i - 1])
				{
					if (arr[i] == arr[i + 1])
					{
						r += 2;
					}
					else
					{
						if (k != arr[i + 1])
						{
							r++;
						}
					}
				}
				else if (arr[i] == arr[i + 1])
				{
					if (k != arr[i - 1])
					{
						r++;
					}
				}
				else
				{
					if (k == arr[i - 1])
					{
						if (k == arr[i + 1])
						{
							r -= 2;
						}
						else r--;
					}
					else if(k == arr[i + 1]) r--;
				}
				printf("%d", r);
				printf("%c", '\n');
			}
		}
		arr[i] = k;
	}

	return 0;
}