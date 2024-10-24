#include <iostream>
using namespace std;

int n, m;
int board[102];
int Bsize = 0;
bool change = false;
int cnt = 1;
int idx = 0;
bool first = true;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        Bsize++;
    }

    while (1)
    {
        change = false;
        cnt = 1;
        idx = 0;
        first = true;

        for (int i = Bsize - 1; i >= 0; --i)
        {
            //같은 것 발견
            if (board[i] == board[i + 1])
            {
                cnt++;
                if (first)
                {
                    idx = i;
                    first = false;
                }
            }
            else
            {
                //터지는 경우
                if (cnt >= m)
                {
                    change = true;
                    int temp[102]; //복사용 배열
                    int tempIdx = 0; //새로운 배열 크기

                    for (int j = 0; j < Bsize; ++j)
                    {
                        if (idx <= j && j < idx + cnt) //1 <= j < 3
                            continue;
                        temp[tempIdx] = board[j];
                        tempIdx++;
                    }
                    //size 갱신
                    Bsize = tempIdx;

                    //board로 copy
                    for (int j = 0; j < Bsize; ++j)
                    {
                        board[j] = temp[j];
                    }
                    break;
                }
            }
        }
        

        if (!change)
            break;
    }
    if (cnt >= m)
    {
        change = true;
        int temp[102]; //복사용 배열
        int tempIdx = 0; //새로운 배열 크기

        for (int j = 0; j < Bsize; ++j)
        {
            if (idx <= j && j < idx + cnt) //1 <= j < 3
                continue;
            temp[tempIdx] = board[j];
            tempIdx++;
        }
        //size 갱신
        Bsize = tempIdx;

        //board로 copy
        for (int j = 0; j < Bsize; ++j)
        {
            board[j] = temp[j];
        }
    }

    cout << Bsize << "\n";
    for (int i = 0; i < Bsize; ++i)
    {
        cout << board[i] << "\n";
    }


    return 0;
}