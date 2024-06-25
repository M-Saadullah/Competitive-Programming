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
		string cat;
		cin >> cat;
		bool flag = 1;
		if (cat[0] == 'm' || cat[0] == 'M')
		{
			for (int i = 0; i < size; i++)
			{
				if (cat[i] == 'm' || cat[i] == 'M')
				{
					if (cat[i + 1] == 'm' || cat[i + 1] == 'M' || cat[i + 1] == 'e' || cat[i + 1] == 'E')
					{
						continue;
					}
					else
					{
						flag = 0;
						cout << "NO" << endl;
						break;
					}
				}
				else if (cat[i] == 'e' || cat[i] == 'E')
				{
					if (cat[i + 1] == 'o' || cat[i + 1] == 'O' || cat[i + 1] == 'e' || cat[i + 1] == 'E')
					{
						continue;
					}
					else
					{
						flag = 0;
						cout << "NO" << endl;
						break;
					}
				}
				else if (cat[i] == 'o' || cat[i] == 'O')
				{
					if (cat[i + 1] == 'o' || cat[i + 1] == 'O' || cat[i + 1] == 'w' || cat[i + 1] == 'W')
					{
						continue;
					}
					else
					{
						flag = 0;
						cout << "NO" << endl;
						break;
					}
				}
				else if (cat[i] == 'w' || cat[i] == 'W')
				{
					if (cat[i + 1])
					{
						if (cat[i + 1] == 'w' || cat[i + 1] == 'W')
						{
							continue;
						}
						else
						{
							flag = 0;
							cout << "NO" << endl;
							break;
						}

					}
					continue;
				}
				else
				{
					flag = 0;
					cout << "NO" << endl;
					break;

				}
			}
			if (flag == 1)
			{
				cout << "Yes" << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}

	}
}