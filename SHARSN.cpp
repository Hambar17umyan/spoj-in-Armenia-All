#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

const int N = 100005;
int arr[N];

int main()
{
	int n;
	cin >> n;
	vector<int>v;
	int i; 
	vector<int>::iterator it;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		it = upper_bound(v.begin(), v.end(), arr[i]);
		if (it == v.end())
		{
			v.push_back(arr[i]);
		}
		else *it = arr[i];
	}
	cout << v.size();

	return 0;
}