
// substring problem

// FB stirng


#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	string FB{ "FBFFBFFBFB" };
	while (t--)
	{
		int size;
		cin >> size;
		string s;
		cin >> s;
		int j = 0;
		int cnt = 0;
		for (int i = 0; i < 10; i++)
		{
			if (s[j] == FB[i])
			{
				j++;
				if (j == size)
				{
					cout << "Yes" << endl;
					break;
				}
			}
			else
			{
				j = 0;
			}
		}
		if(j!=size)
			cout << "No" << endl;
	}
}