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
unordered_map<pair<int, int>, int, pair_hash> um;
int d[102][102];
pair<int, int> board[102];
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
        um[{a, b}] = idx;
        board[idx] = { c,d };
        idx++;
        um[{c, d}] = idx;
        board[idx] = { a,b };
        idx++;
    }

    d[0][0] = 1;

    for (int x = 1; x <= n; ++x)
    {
        //(x,0) 이 있는 경우
        if (um.find({ x, 0 }) != um.end())
        {
            int tempIdx = um[{x, 0}];
            if (board[tempIdx].first == x - 1)
            {
                continue;
            }
        }
        d[x][0] = d[x - 1][0];
    }
    for (int y = 1; y <= m; ++y)
    {
        if (um.find({ 0, y }) != um.end())
        {
            int tempIdx = um[{0, y}];
            if (board[tempIdx].second == y - 1)
            {
                continue;
            }
        }
        d[0][y] = d[0][y - 1];
    }
    
    for(int x = 1; x <= n; ++x)
    {
        for(int y = 1; y <= m; ++y)
        {            
            if (um.find({ x, y }) != um.end())
            {
                int tempIdx = um[{x, y}];
                if (board[tempIdx].first == x - 1)
                {
                    d[x][y] = d[x][y-1];
                    continue;
                }
                else if (board[tempIdx].second == y - 1)
                {
                    d[x][y] = d[x-1][y];
                    continue;
                }                
            }
            d[x][y] = d[x - 1][y] + d[x][y - 1];
        }
    }
    //Print();

    cout << d[n][m];
    return 0;
}