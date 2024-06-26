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
		int size;
		cin >> size;
		vector<int> vec(size);
		for (int i = 0;i < size;i++)
		{
			cin >> vec[i];
		}

		sort(vec.begin(), vec.end());
		int min = INT_MAX;
		int idx = 0;
		for (int i = 1;i < size;i++)
		{
			if (vec[i] - vec[i - 1]<min)
			{
				idx = i;
				min = vec[i] - vec[i - 1];
			}
		}
		cout << vec[idx-1]<<" ";
		int i = idx+1;
		while (i < size)
		{
			cout << vec[i] << " ";
			i++;
		}
		i = 0;
		while (i < idx - 1)
		{
			cout << vec[i] << " ";
			i++;
		}
		cout << vec[idx] << " ";
		cout << endl;
	}
}