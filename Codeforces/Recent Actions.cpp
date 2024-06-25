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
		int* arr1 = new int[size];
		int* arr2 = new int[size] {0};
		for (int i = 0; i < size; i++)
		{
			arr1[i] = i + 1;
		}
		int x = size - 1;
		int size2;
		cin >> size2;
		int temp;
		int index;
		int a = 1;
		for (int i = 0; i < size2; i++)
		{
			cin >> temp;
			if (x >= 0)
			{
				bool flag = 0;
				for (int j = 0; j < size; j++)
				{
					if (temp == arr1[j])
					{
						flag = 1;
						a++;
						break;
					}
				}
				if (!flag)
				{
					arr2[x] = a;
					a++;
					arr1[x] = temp;
					x--;
				}
			}

		}
		for (int i = 0; i < size; i++)
		{
			if (arr2[i] != 0)
				cout << arr2[i] << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
		delete[] arr1;
		arr1 = nullptr;
		delete[] arr2;
		arr2 = nullptr;
	}
}