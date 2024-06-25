#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		vector<long> vec(size);

		map<int, int> map;
		double sum = 0;
		for (int i = 0;i < size;i++)
		{
			cin >> vec[i];
			sum += vec[i];
			
			map[vec[i]]++;
		}

		double avg = sum / size;
		if (avg*2 != long(avg*2))
		{
			cout << 0 << endl;
			continue;
		}
		long target = avg * 2;

		long long result = 0;
		for (int i = 0;i < size;i++)
		{
			if (map[vec[i]] > 0 && map[target - vec[i]] > 0)
			{
				if (vec[i] == target - vec[i])
				{
					result += map[vec[i]] - 1;
				}
				else
				{
					result += map[target - vec[i]];

				}
			}
		}
		cout << result / 2 << endl;

	}


}