#include <iostream>
#include <set>
using namespace std;

int arr[30];
int main()
{
	string s;
	int i, j, n, m;
	cin >> s;
	n = s.size();
	set<char>st;
	st.insert(s[n - 1]);
	arr[s[n - 1] - 'a'] = n - 1;
	for (i = n - 2; i >= 0; i--)
	{
		m = st.size();
		st.insert(s[i]);
		if (st.size() == m)
		{
			cout << i + 1 << ' ';
			for (j = 0; j < i; j++)
			{
				cout << j + 1 << ' ';
			}
			cout << arr[s[i] - 'a'] + 1 << endl;
			return 0;
		}
		arr[s[i] - 'a'] = i;
	}
	cout << 0 << endl;

	return 0;
}