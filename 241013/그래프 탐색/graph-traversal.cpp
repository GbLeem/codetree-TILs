#include <iostream>
using namespace std;

int board[1002][1002];
bool visit[1002];
int answer = 0;
int n, m;

void DFS(int cur)
{
    for(int i = 1; i <= n; ++i)
    {
        if(board[cur][i] && !visit[i])
        {   
            visit[i] = 1;
            answer++;
            DFS(i);
        }
    }
}
int main() 
{
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = 1;
    }

    visit[1] = 1;
    DFS(1);

    cout << answer;

    return 0;
}