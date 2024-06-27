#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
    int size;
    cin >> size;
    vector<string> vec(size);
    map<string, string> map;
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
        cin >> map[vec[i]];
    }
    short count = 0;
    for (int i = 0; i < size; i++)
    {
        while (map.find(map[vec[i]]) != map.end())
        {
            string temp = map[vec[i]];
            map[vec[i]] = map[temp];
            map.erase(temp);
            count++;
        }
    }
    //print how much remaining
    cout << map.size()-count << endl;
    for (int i = 0; i < size; i++)
    {
        if (map[vec[i]] != "")
        {
            cout << vec[i] << " " << map[vec[i]] << endl;
        }
    }

    return 0;
}
