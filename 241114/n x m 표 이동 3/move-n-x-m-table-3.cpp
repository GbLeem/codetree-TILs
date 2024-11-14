#include <iostream>
#include <unordered_map>
using namespace std;

struct pair_hash
{
    size_t operator()(const pair<int, int>& p) const
    {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};

int n, m, k;
unordered_multimap<pair<int, int>, int, pair_hash> um; //좌표 저장
long long d[102][102];
pair<int, int> board[202]; //좌표저장
int idx = 0;

void Print()
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //um[{a, b}] = idx;
        um.insert({ { a, b }, idx });
        board[idx] = { c,d };
        idx++;
        //um[{c, d}] = idx;
        um.insert({ {c,d}, idx });
        board[idx] = { a,b };
        idx++;
    }

    d[0][0] = 1;

    for (int x = 1; x <= n; ++x)
    {
        //(x,0) 이 있는 경우
        bool canGo = true;
        if (um.find({ x, 0 }) != um.end())
        {            
            auto tempIdxs = um.equal_range({ x, 0 }); // idx들 

            for (auto it = tempIdxs.first; it != tempIdxs.second; ++it)
            {
                //못가는 경우
                if (board[it->second].first == x - 1)
                {
                    canGo = false;
                    break;
                }
            }
        }
        if(canGo)
            d[x][0] = d[x - 1][0];
    }

    for (int y = 1; y <= m; ++y)
    {
        bool canGo = true;
        if (um.find({ 0, y }) != um.end())
        {
            auto tempIdxs = um.equal_range({ 0, y });

            for (auto it = tempIdxs.first; it != tempIdxs.second; ++it)
            {
                //못가는 경우
                if (board[it->second].second == y - 1)
                {
                    canGo = false;
                    break;
                }
            }
        }
        if(canGo)
            d[0][y] = d[0][y - 1];
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            /*if (x == n && y == m)
            {
                cout << "Ok\n";
            }*/
            bool canXY = true;
            if (um.find({ x, y }) != um.end())
            {
                auto tempIdxs = um.equal_range({ x, y });

                //막힌 경우
                //자신보다 x가 하나 작은 좌표는 못씀
                bool canX = true;
                bool canY = true;
                for (auto it = tempIdxs.first; it != tempIdxs.second; ++it)
                {
                    if (board[it->second].first == x - 1)
                    {
                        canX = false;
                        canXY = false;
                        //d[x][y] = d[x][y - 1];
                        //continue;
                    }
                    //자신보다 y가 하나 작은 좌표는 못씀
                    else if (board[it->second].second == y - 1)
                    {
                        canY = false;
                        canXY = false;
                        //d[x][y] = d[x - 1][y];
                        //continue;
                    }
                }
                if (canX)
                    d[x][y] = d[x - 1][y];
                else if (canY)
                    d[x][y] = d[x][y - 1];
                else if (canX && canY)
                    canXY = true;
                else if (!canX && !canY)
                    d[x][y] = 0;
            }
            //안막힌 경우
            if (canXY)
                d[x][y] = d[x - 1][y] + d[x][y - 1];
        }
    }
    //Print();

    cout << d[n][m];
    return 0;
}