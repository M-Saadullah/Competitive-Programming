#include<iostream>
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
		vector<int> vec(size);
		for (int i = 0; i < size; i++)
		{
			cin >> vec[i];
		}
		if (size == 1)
		{
			cout << vec[0] << endl;
			continue;
		}

		long long total_sum = vec[0];
		cout << vec[0] << " ";
		int no_of_odds = 0;
		if(vec[0]%2==1)
			no_of_odds = 1;
		for (int i = 1; i < size; i++)
		{
			int no_to_remove = 0;
			if (vec[i] % 2 == 1)
				no_of_odds++;
			total_sum += vec[i];
			if (no_of_odds % 3 == 1)
				no_to_remove++;
			no_to_remove += no_of_odds / 3;
			cout << total_sum - no_to_remove << " ";
		}
		cout << endl;
	}
}