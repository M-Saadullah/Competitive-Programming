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
		int l, r;
		cin >> l >> r;
		int target = 0;
		int result = 0;
		int start;
		vector<int> vec(size);
		for (int i = 0; i < size; i++)
		{
			cin >> vec[i];
			if (vec[i] < l)
			{
				if (target == 0)
				{
					start = i;
				}
				target += vec[i];
				if (target >= l && target <= r)
				{
					result++;
					target = 0;
				}
				else if (target > r)
				{
					while (target > r)
					{
						if (start < i)
						{
							target -= vec[start];
							if (target >= l && target <= r)
							{
								result++;
								target = 0;
								break;
							}
							start++;
						}
						else
						{
							target = 0;
						}
					}
				}
			}
			else if (vec[i] >= l && vec[i] <= r)
			{
				result++;
				target = 0;
			}
			else
			{
				target = 0;
			}
		}
		cout << result << endl;
	}
}