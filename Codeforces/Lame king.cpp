#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		int cnt;
		cin >> a >> b;
		int x = abs(a) - abs(b);
		cnt = (abs(a) + abs(b) - abs(x));
		if (abs(x) != 0)
			cnt += (abs(x) * 2) - 1;
		cout << cnt << endl;
	}
}