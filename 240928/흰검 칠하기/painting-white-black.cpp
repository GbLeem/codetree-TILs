#include <iostream>
using namespace std;

pair<int, string> board[200002]; // 1 2 10 20 -> 22면 끝

int main() 
{
    int n; 
    int start = 0;
    
    cin >>n;
    
    for(int i = 0; i < n; ++i)
    {
        int num;
        char ch;
        cin >> num >> ch;

        //흰색
        if(ch == 'L')
        {
            for(int j = start + 100000 - 1; j >= start - num + 100000; --j)
            {
                board[j].first++;

                if(board[j].second.back() == 'G')
                    continue;
                board[j].second += 'W';                

                int black = 0;
                int white = 0;

                for(int k = 0; k < board[j].second.size(); ++k)
                {
                    if(board[j].second[k] == 'B')
                        black++;
                    else if(board[j].second[k] == 'W')
                        white++;
                }
                if(black >=2 && white >= 2)
                    board[j].second = 'G';
            }

            start = start - num;
        }
        //검정색
        else //R
        {
            for(int j = start + 100000; j < (start + num + 100000); ++j)
            {
                board[j].first++;

                if(board[j].second.back() == 'G')
                    continue;
                board[j].second += 'B';

                int black = 0;
                int white = 0;

                for(int k = 0; k < board[j].second.size(); ++k)
                {
                    if(board[j].second[k] == 'B')
                        black++;
                    else if(board[j].second[k] == 'W')
                        white++;
                }
                if(black >= 2 && white >= 2)
                    board[j].second = 'G';
            }

            start = start + num;        
        }        
    }

    int ba = 0;
    int wa = 0;
    int ga = 0;

    for(int i = 0; i <= 200000; ++i)
    {
        if(board[i].second.back() == 'B')
            ba++;
        else if(board[i].second.back() == 'W')
            wa++;
        else if(board[i].second.back() == 'G')
            ga++;
    }
    cout << wa <<" "<<ba <<" "<<ga;
    return 0;
}