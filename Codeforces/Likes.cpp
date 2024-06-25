#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int cnt=0;
		int* arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
			if (arr[i] < 0)
				cnt++;
		}
		int x = cnt;
		int i=1;
		for (i; i <= size - cnt; i++)
		{
			cout << i << " ";
		}
		for (i= i-2; cnt--; i--)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int j = 0; j < x; j++)
		{
			cout << 1 << " " << 0 << " ";
		}
		cnt = (size - (x * 2));
		for (int j = 1; j <= cnt; j++)
			cout << j << " ";
		cout << endl;
	}
}