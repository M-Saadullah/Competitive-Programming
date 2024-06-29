#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, k;
		cin >> x >> y >> k;
		while (k)
		{
			int req_to_divide = y - (x % y);
			if (k - req_to_divide >= 0)
			{
				x += req_to_divide;
				while ((x % y) == 0)
				{
					x = x / y;
				}
				k = k - req_to_divide;
			}
			else
			{
				x += k;
				break;
			}
			if (x == 1)
			{
				x +=(k % (y-1));
				break;
			}

		}
		cout << x << endl;
	}
}