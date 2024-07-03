#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	bool flag = true;
	int result = 0;
	for (int k = 0; k < s.length()&&flag; k++)
	{
		for (int i = s.length() - k-1; i > 0&&flag; i--)
		{
			string substr = s.substr(k, i);
			for (int j = k+1; j <= s.length() - i; j++)
			{
				if (substr == s.substr(j, i))
				{
					result = max(result, int(substr.length()));
				}
			}
		}
	}
	cout << result << endl;

}