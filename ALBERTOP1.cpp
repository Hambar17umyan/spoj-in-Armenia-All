#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> arr;
int main()
{
	long long i, j, k = 0, l, m, n, o, p, z = 0, mx = -30000000008, mxi;
	cin >> n >> o;
	bool b = true;
	int fpz = -1, lpz, fpk = -1, lpk;
	for (i = 0; i < n; i++)
	{
		cin >> o;
		arr.push_back(o);
		if (arr[i] > mx)
		{
			mx = arr[i];
			mxi = i;
		}
		if (arr[i] >= 0)
		{
			b = false;
			if (i % 2 == 0)
			{
				if (fpk == -1)
				{
					fpk = i;
				}
				lpk = i;
			}
			else
			{
				if (fpz == -1)
				{
					fpz = i;
				}
				lpz = i;
			}
		}
		k += (i % 2 == 0) * (arr[i] >= 0) * arr[i];
		z += (i % 2 == 1) * (arr[i] >= 0) * arr[i];
	}
	if (n == 2)
	{
		cout << max(arr[0], arr[1]) << endl;
		if (max(arr[0], arr[1]) == arr[0])
		{
			cout << 1 << endl << 1;
		}
		else
		{
			cout << 1 << endl << 2;
		}
		return 0;
	}
	else if (n == 3)
	{
		cout << max(max(arr[0], arr[1]), max(arr[2], arr[0] + arr[2])) << endl;
		if (max(max(arr[0], arr[1]), max(arr[2], arr[0] + arr[2])) == arr[0])
		{
			cout << 2 << endl << 3 << ' ' << 2;
		}
		else if (max(max(arr[0], arr[1]), max(arr[2], arr[0] + arr[2])) == arr[2])
		{
			cout << 2 << endl << 1 << ' ' << 1;
		}
		else
		{
			cout << 1 << '\n' << 2 << endl;
		}
		return 0;
	}
	queue<int>q;
	if (b)
	{
		cout << mx << endl;
		cout << n - 1 << endl;
		for (i = 0; i < n - mxi - 1; i++)
		{
			cout << n - i << ' ';
		}
		for (i = 0; i < mxi; i++)
		{
			cout << 1 << ' ';
		}
		return 0;
	}
	else
	{
		cout << max(k, z) << endl;
		if (max(k, z) == z)
		{
			l = 0;
			lpz -= fpz;
			for (i = 0; i < fpz;)
			{
				q.push(1);
				arr.erase(arr.begin());
				fpz--;
				n--;
			}
			for (i = lpz + 1; i < n ; i++)
			{
				q.push(n);
				arr.erase(arr.begin() + n - 1);
				n--;
			}
			for (i = 0; i < n; i+=2)
			{
				if (arr[i] < 0)
				{
					arr[i] = arr[i - 1] + arr[i + 1];
					q.push(i + 1);
					arr.erase(arr.begin() + (i - 1));
					arr.erase(arr.begin() + (i));
					n -= 2;
					i-=2;
				}
			}
			o = 0;
			for (i = 1; i < n; i+=2)
			{
				q.push(2);
			}
			cout << q.size() << endl;
			while (q.size() != 0)
			{
				cout << q.front() << ' ';
				q.pop();
			}
		}
		else
		{
			l = 0;
			lpk -= fpk;
			for (i = 0; i < fpk;)
			{
				q.push(1);
				arr.erase(arr.begin());
				fpk--;
				n--;
			}
			for (i = lpk + 1; i < n; i++)
			{
				q.push(n);
				arr.erase(arr.begin() + n - 1);
				n--;
			}
			for (i = 0; i < n; i += 2)
			{
				if (arr[i] < 0)
				{
					arr[i] = arr[i - 1] + arr[i + 1];
					q.push(i + 1);
					arr.erase(arr.begin() + (i - 1));
					arr.erase(arr.begin() + (i));
					n -= 2;
					i-=2;
				}
			}
			o = 0;
			for (i = 1; i < n; i += 2)
			{
				q.push(2);
			}
			cout << q.size() << endl;
			while (q.size() != 0)
			{
				cout << q.front() << ' ';
				q.pop();
			}
		}
	}
	return 0;
}