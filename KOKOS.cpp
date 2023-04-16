#include <iostream>
using namespace std;

struct mem {
	int num;
	short stat;
	int ind;
	//0 - arandzin mard
	//1 - pak dzerq
	//2 - bac dzerq

	mem *prev, *next;
};

mem arr[505];
int main()
{
	int n, k, i, j;
	cin >> k >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	arr[2].prev = &arr[2 + 3 * (n - 1)];
	arr[2 + 3 * (n - 1)].next = &arr[2];
	arr[2 + 3 * (n - 1)].prev = &arr[2 + 3 * (n - 2)];
	arr[2].next = &arr[5];
	int y = 1;
	for (i = 2; i <= 2 + 3 * (n - 1); i += 3, y++)
	{
		arr[i].num = y;
		arr[i].stat = 0;
		arr[i - 1].num = y;
		arr[i + 1].num = y;
		arr[i].ind = i;
		arr[i - 1].ind = i - 1;
		arr[i + 1].ind = i + 1;
		if (i > 2 && i < 2 + 3 * (n - 1))
		{
			arr[i].prev = &arr[i - 3];
			arr[i].next = &arr[i + 3];
		}
	}
	mem h = arr[2];
	int x = k;
	while (h.prev != h.next || &h != h.next)
	{
		if (x == 1)
		{
			x = k;
			if (h.stat == 0)
			{
				(*h.prev).next = &arr[h.ind - 1];
				(*h.next).prev = &arr[h.ind + 1];
				arr[h.ind - 1].stat = 1;
				arr[h.ind + 1].stat = 1;
				arr[h.ind - 1].prev = h.prev;
				arr[h.ind + 1].next = h.next;
				arr[h.ind - 1].next = &arr[h.ind + 1];
				arr[h.ind + 1].prev = &arr[h.ind - 1];
				h = arr[h.ind - 1];
			}
			else if (h.stat == 1)
			{
				arr[h.ind].stat = 2;
				h = *h.next;
			}
			else if (h.stat == 2)
			{
				(*h.prev).next = h.next;
				(*h.next).prev = h.prev;
				h = *h.next;
			}
		}
		else
		{
			x--;
			h = *h.next;
		}
	}
	cout << h.num << endl;

	return 0;
}