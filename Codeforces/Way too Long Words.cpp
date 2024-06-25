#include<iostream>
using namespace std;
int main()
{
	long long int m, n, x, t, res, sum, i, j;
	cin >> m;
	for (i = 0; i < m; i++)
	{
		sum = 0;
		cin >> n >> x >> t; // 3 3 10
		res = t / x;
		if (res < n)
		{
			sum = sum + res * (res - 1) / 2;
			sum = sum + (n - res) * res;
		}
		else
		{
			sum = sum + n * (n - 1) / 2;
		}
		cout << sum << endl;

	}

}