#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n > 26)
	{
		cout << -1; return 0;
	}
	string s;
	cin >> s;
	int arr[256]{ 0 };
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		arr[s[i]] += 1;
		if (arr[s[i]] > 1)
		{
			sum += 1;
		}
	}
	cout << sum << endl;

	return 0;
}
