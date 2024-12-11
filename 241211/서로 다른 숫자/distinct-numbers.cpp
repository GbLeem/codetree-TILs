#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> us;
int n;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        us.insert(num);
    }

    cout <<us.size();
    return 0;
}