#include<iostream>
using namespace std;
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		long int a, b, c, d, f, cnt;
		cin >> a >> b >> c >> d;
		if (b > d)
		{
			cout << -1 << endl;
			continue;
		}
		cnt = d - b;
		a += cnt;
		b += cnt;
		if (a < c && b == d)
		{
			cout << -1 << endl;
			continue;
		}
		cnt += f = a - c;
		a = a - f;
		if (a == c && b == d)
		{
			cout << cnt << endl;
		}
		else
			cout << -1 << endl;
	}
}
