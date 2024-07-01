#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		string s;
		cin >> s;
		string str;
		if (size > 1)
		{
			str += s[0];
		}
		int temp = 0;
		for (int i = 1; i < size; i++)
		{
			if (s[i] == s[i - 1])
				temp++;
			else
				temp = 0;
			if (temp < 2)
			{
				str += s[i];
			}
		}
		int result = -1;
		for (int i = 0; i < size-2; i++)
		{
			if (s[i] == s[i + 2])
				result--;
		}
		cout << result + size << endl;
	}
}