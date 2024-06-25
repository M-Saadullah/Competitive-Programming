#include<iostream>
#include<string>
using namespace std;

struct SymbolValue
{
	char symbol;
	int value;
};

int main()
{
	SymbolValue SV[7]{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
	string s;
	int i = 0;
	int sum = 0;
	cin >> s;
	int temp_sum;
	while (i < s.length())
	{
		temp_sum = 0;
		for (int j = i; j <= i + 4; j++)
		{
			if (s[j] == s[j + 1])
			{
				temp_sum++;
			}
			else
			{
				break;
			}
		}
		if (temp_sum == 3)
		{
			cout << -1 << endl;
			return 0;
		}
		if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
		{
			if (s[i + 1] == 'V')
			{
				sum += 4;
			}
			else
			{
				sum += 9;
			}
			i += 2;
			continue;
		}
		else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
		{
			if (s[i + 1] == 'L')
			{
				sum += 40;
			}
			else
			{
				sum += 90;
			}
			i += 2;
			continue;
		}
		else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
		{
			if (s[i + 1] == 'D')
			{
				sum += 400;
			}
			else
			{
				sum += 900;
			}
			i += 2;
			continue;
		}
		for (int j = 0; j < 7; j++)
		{
			if (s[i] == SV[j].symbol)
			{

				sum += SV[j].value;
				break;
			}
		}
		i++;
	}
	cout << sum;
}


