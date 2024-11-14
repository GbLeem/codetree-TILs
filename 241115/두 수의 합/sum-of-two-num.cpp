#include <iostream>
#include <unordered_map>
using namespace std;

int n;
long long k;
unordered_map<long long , long long> um;
int board[100'002];
int answer = 0;

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        um[board[i]]++;
    }

    for(int i = 0; i < n; ++i)
    {
        long long other = k - board[i]; 

        if(um[other] >= 1)
        {
            if(other == board[i])
            {
                um[other]--;
                answer += um[other]; // 4 3 2 1 
            }
            else
            {
                answer += um[other];                
                um[board[i]] = 0;
            }
        }
    }

    cout << answer;
    return 0;
}