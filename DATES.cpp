#include <iostream>
#include <set>
#include <string>
using namespace std;

int mdays[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
struct date {
	int d, m, y;
};
date next_day(date d)
{
	d.d++;
	if (mdays[d.m - 1] < d.d)
	{
		d.d = 1;
		d.m++;
	}
	if (d.m > 12)
	{
		d.m = 1;
		d.y++;
	}
	return d;
}
date todate(string s)
{
	date res;
	int i = 2;
	res.d = (s[0] - '0');
	if (s[1] != '.')
	{
		i++;
		res.d *= 10;
		res.d += (s[1] - '0');
	}
	res.m = (s[i] - '0');
	i += 2;
	if (s[i] == '.')
	{
		res.m *= 10;
		res.m += (s[i - 1] - '0');
		i++;
	}
	res.y = 0;
	for (; i < s.size(); i++)
	{
		res.y *= 10;
		res.y += (s[i] - '0');
	}
	return res;
}
int main()
{
	date d;
	string dt;
	cin >> dt;
	d = todate(dt);
	int res = 0;
	while (true)
	{
		res++;
		d = next_day(d);
		string s = to_string(d.d);
		s += to_string(d.m);
		s += to_string(d.y);
		set<char>st;
		for (int i = 0; i < s.size(); i++)
		{
			st.insert(s[i]);
		}
		if (st.size() > 2)
		{
			continue;
		}
		cout << res << endl;
		return 0;
	}

	return 0;
}