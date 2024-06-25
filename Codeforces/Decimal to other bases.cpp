//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	short base;
//	cout << "Enter base you want: ";
//	cin >> base;
//	int no;
//	cout << "Enter decimal no you want to convert: ";
//	cin >> no;
//	double x = log2(no);
//	int size;
//	x > int(x) ? size = x + 1 : size = x;
//	cout << size << endl;
//	int* binary = new int[size] {0};
//	int i = 1;
//	while (no > 0)
//	{
//		binary[size - i] = no % base;
//		no = no / base;
//		i = i + 1;
//	}
//	for (int j = 0; j < size; j++)
//	{
//		cout << binary[j] << " ";
//	}
//	cout << endl;
//}



#include<iostream>
#include<string>
using namespace std;
int main()
{
	int base;
	string no;
	cout << "Enter no: ";
	cin >> no;
	int size = no.length();
	cout << "Enter base of the number: ";
	cin >> base;
	int decimal = 0;
	int i = 1;
	while (i <= size)
	{
		if (no[size - i] >= '0' && no[size - i] <= '9')
		{
			decimal += ((no[size - i] - '0') * (pow(base, i - 1)));
		}
		else
		{
			decimal += (((no[size - i] - 'A') + 10) * pow(base, i - 1));
		}
		i++;
	}
	cout << decimal << endl;
}
