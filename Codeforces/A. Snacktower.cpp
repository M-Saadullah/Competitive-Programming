#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int size;
	cin >> size;
	int target = size;
	vector<bool> vec(size+1,false);
	for (int i = 0; i < size; i++)
	{
		int item;
		cin >> item;
		vec[item] = true;
		while (vec[target])
		{
			cout << target << " ";
			target--;
		}
		cout << endl;

	}
}