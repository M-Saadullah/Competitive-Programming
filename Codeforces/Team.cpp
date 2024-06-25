#include<iostream>
using namespace std;
int main()
{
	int size;
	cin >> size;
	bool** arr = new bool* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new bool[3]{0};
	}
	int temp_count = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		temp_count = 0;
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
			temp_count += arr[i][j];
		}
		if (temp_count >= 2)
		{
			count++;
		}
	}
	cout << count<<endl;
}