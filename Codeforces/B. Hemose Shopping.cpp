#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size, x;
		cin >> size >> x;
		bool someFlag = false;
		if (size >= x * 2)
		{
			someFlag = true;
		}
		if (someFlag)
		{
			for (int i = 0; i < size; i++)
			{
				int temp;
				cin >> temp;
			}
			cout << "YES" << endl;
			continue;
		}
		vector<int> vec(size);
		for (int i = 0; i < size; i++)
		{
			cin >> vec[i];
		}
		vector<int> newVec(size);
		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		sort(vec.begin(), vec.end());
		bool flag = true;
		for (int i = size - x; i < x; i++)
		{
			if (vec[i] != newVec[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}


	}
}