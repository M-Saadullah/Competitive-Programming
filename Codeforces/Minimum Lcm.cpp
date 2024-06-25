#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

long long int calculateGCD(long long int a, long long int b)
{
	long long int x;
	while (b > 0)
	{
		x = a % b;
		a = b;
		b = x;
	}
	return a;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int no;
		cin >> no;
		int temp = 0;
		int x = 0, y = 0;
		for (int i = 1; i <= no / 2; i++)
		{
			int a = no - i;
			int b = calculateGCD(a, i);
			int gcd = max(b, temp);
			if (b > temp)
			{
				x = a;
				y = i;
			}
			temp = gcd;
		}
		cout << x << " " << y << endl;

	}
}




//#include <iostream>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, i, j, k, a = 1, b = 1;
//		cin >> n;
//		for (i = 2; i * i <= n; i++) {
//			if (n % i == 0) {
//				a = n / i;
//				break;
//			}
//		}
//		cout << a << " " << n - a << endl;
//	}
//}