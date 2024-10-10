#include <iostream>
using namespace std;

char board[10002];

int main() 
{
    int n, k;
    cin >> n >> k;

    int maxNum = 0;
    for(int i = 0; i < n; ++i)
    {
        int num;
        char ch;

        cin >> num >> ch;
        
        if(maxNum < num)
            maxNum = num;

        board[num] = ch;
    }    

    int answer = 0;

    for(int i = 1; i <= maxNum - k; ++i)
    {
        int temp = 0;
        for(int j = i; j <= i + k; ++j) // 1 ~ 7
        {
            if(board[j] == 'G')
                temp += 1;
            else if(board[j] == 'H')
                temp += 2;
        }
        answer = max(answer, temp);
    }
    
    cout << answer;

    return 0;
}