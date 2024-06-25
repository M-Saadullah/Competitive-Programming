#include<iostream>
#include<math.h>
#include<string>
using namespace std;

bool getBit(int mask, int j)
{
	return (mask & (1 << j)) != 0;
}

bool isPalindrome(string s)
{
	int size = s.length();
	for (int i = 0; i < size / 2; i++)
	{
		if (s[i] != s[size - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string s;
	cin >> s;
	int strSize = s.length();
	int mask = 1;
	int arrSize = (pow(2, strSize)) - 1;
	string* arr = new string[arrSize];
	for (int i = 0; i < arrSize; i++, mask++)
	{
		for (int j = 0; j < strSize; j++)
		{
			if (getBit(mask, j))
			{
				arr[i] += s[j];
			}
		}
	}
	string output = { "" };
	for (int i = 0; i < arrSize; i++)
	{
		if (isPalindrome(arr[i]))
		{
			if (arr[i] > output)
			{
				output = arr[i];
			}
		}
	}
	cout << output << endl;

}


//#include<iostream>
//#include<string>
//
//using namespace std;
//int main() {
//	string s;
//	cin >> s;
//	char x = s[0];
//	for (int i = 0; i < s.size(); i++) {
//
//		if (x <= s[i]) {
//			x = s[i];
//		}
//	}
//
//	for (int i = 0; i < s.size(); i++) {
//		if (x == s[i]) {
//			cout << s[i];
//		}
//	}
//	return 0;
//}
