#include<iostream>
using namespace std;
int main()
{
	//int n;
	////cin >> n;
	////int onMask = (1 >> n);
	////int offMask = ~(1 >> n);
	////cout << onMask << endl;
	////cout << offMask << endl;
	//n = 75;    // 1001011
	////cout << (n & (1 + (~n))) << endl;
	//int i = 0;
	//while (n != 0)
	//{
	//	n = n & (~(n & -n));
	//	i++;
	//}
	//cout << i << endl;

	//cout << x << endl;
	//cout << n << endl;



	int* arr = new int[9] {1, 2, 3, 4, 5, 1, 2, 3, 4};
	int uni = 0;
	for (int i = 0; i < 9; i++)
	{
		uni = uni ^ arr[i];
	}
	cout << uni << endl; 
}