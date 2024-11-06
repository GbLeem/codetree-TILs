#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<string, int> um;
unordered_map<int, string> um2;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        um[str] = i + 1;
        um2[i + 1] = str;
    }

    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;

        if ('a' <= str[0] && str[0] <= 'z')
        {
            cout << um[str] << "\n";
        }
        else
        {
            int num = stoi(str);
            cout << um2[num] << "\n";
        }
    }
    return 0;
}