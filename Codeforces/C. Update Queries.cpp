#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> indeces(m);
		for (int i = 0; i < m; i++)
		{
			cin >> indeces[i];
		}
		sort(indeces.begin(), indeces.end());
		string c;
		cin >> c;
		sort(c.begin(), c.end());
		int strt = 0, end = m - 1;
		for (int i = 0; i < m-1; i++)
		{
			if (indeces[i] == indeces[i + 1])
			{
				s[indeces[i]-1] = c[end--];
			}
			else
			{
				s[indeces[i]-1] = c[strt++];
			}
		}
		s[indeces[m - 1] - 1] = c[strt];
		cout << s << endl;

	}
}