#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 0)
		{
			cout << 1 << endl;
			continue;
		}
		long long sum = a + b + c + d;
		int target = a;
		int minus = 0;
		int x = min(c, b);
		x = (b + c) - (x * 2);
		if (x >= target)
		{
			minus = x - target;
			minus += (d - 1);
		}
		else
		{
			target = target - x;
			
			if (d > target)
			{
				minus += (d - target - 1);
			}
			else
			{
				target = target - d;
				minus = minus - target - 1;
			}
		}
		if (minus > 0)
			sum -= minus;
		cout << sum << endl;
	}
}