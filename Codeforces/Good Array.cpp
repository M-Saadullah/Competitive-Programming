
//Good array

#include<iostream>
using namespace std;
int main()
{
	const int size = 4;
	int arr[size]{ 8,3,5,2 };
	int max = 0, sum = 0;
	int temp;
	for (int i = 0; i < size; i++)
	{
		temp = arr[i];
		arr[i] = 0;
		sum = 0;
		max = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] >= max)
			{
				sum += max;
				max = arr[j];
			}
			else
			{
				sum += arr[j];
			}
		}
		if (sum == max)
		{
			cout<<i+1<<" ";
		}
		arr[i] = temp;
	}

}



// The way words too long



#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int x;
	cin >> x;
	string* y = new string[x];
	for (int i = 0; i < x; i++)
	{
		cin >> s;
		if (s.length() <= 10)
		{
			y[i] = s;
		}
		else
		{
			y[i].append(s, 0, 1);
			int count = s.length() - 2;
			y[i].append(to_string(count));
			y[i].append(s, s.length() - 1, 1);
		}
	}
	for (int i = 0; i < x; i++)
	{
		cout << y[i] << endl;
	}
}