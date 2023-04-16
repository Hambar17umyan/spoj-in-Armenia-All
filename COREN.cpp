#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void winner(bool b)
{
	if (!b)
		cout << "Slavko\n";
	else cout << "Mirko\n";
}
int main()
{
	int n;
	cin >> n;
	set<int>s1;
	set<int>s2;
	while (n--)
	{
		int i;
		cin >> i;
		s1.insert(i);
		s2.insert(-i);
	}
	bool b = 0;
	while (s1.size() > 3)
	{
		if (!b)
		{
			set<int>::iterator it = find(s2.begin(), s2.end(), -*s1.begin());
			s2.erase(it, it);
			int i = *upper_bound(s1.begin(), s1.end(), *s1.begin());
			s1.erase(s1.begin(), s1.begin());
			s1.insert(i);
			s2.insert(-i);
		}
		else
		{
			set<int>::iterator it = find(s1.begin(), s1.end(), -*s2.begin());
			s1.erase(it, it);
			int i = *upper_bound(s2.begin(), s2.end(), *s2.begin());
			s2.erase(s2.begin(), s2.begin());
			s2.insert(i);
			s1.insert(-i);
		}
		b = !b;
	}
	winner(b);
	cout << *s1.begin() << ' ' << -*s2.begin() << endl;

	return 0;
}