#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int i = 0;
		for (i; i < s1.size(); i++)
		{
			if (s1[i] == s2[i])
				continue;
			if (s2[i] > s1[i])
				swap(s2, s1);
			break;

		}
		for (int j= i+1; j < s1.length(); j++)
		{
			if (s1[j] > s2[j])
			{
				swap(s1[j], s2[j]);
			}
		}

		cout << s1 << endl;
		cout << s2 << endl;
	}
}