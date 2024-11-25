#include <iostream>
using namespace std;

int n, m, k;
int board[18][18];
int dp1[18][18];
int dp2[18][18];

void Print()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cout << board[i][j]<<" ";
        }
        cout << '\n';
    }   
}


int main() 
{
    cin >> n >> m >> k;

    int value = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            board[i][j] = value;
            value++;
        }
    }    

    //(1, 1) -> (a, b)
    //(a, b) -> (n, m)
    int a = n;
    int b = m;
    if(k != 0)
    {
        a = k / m + 1;
        b = k % m;
    }    

    for(int i = 1; i <= n; ++i)    
        dp1[i][1] = 1;
        
    for(int i = 1; i <= m; ++i)    
        dp1[1][i] = 1;
    
    for(int i = a; i <= n; ++i)    
        dp2[i][b] = 1;

    for(int i = b; i <= m; ++i)    
        dp2[a][i] = 1;
    
    
    for(int i = 2; i <= a; ++i)
    {
        for(int j = 2; j <= b; ++j)
        {
            dp1[i][j] = dp1[i-1][j] + dp1[i][j-1];
        }
    }
    
    for(int i = a + 1; i <= n; ++i)
    {
        for(int j = b + 1; j <= m; ++j)
        {
            dp2[i][j] = dp2[i-1][j] + dp2[i][j-1];
        }
    }
    
    // cout << dp1[a][b] << "\n";
    // cout << dp2[n][m] << "\n";
    cout << dp1[a][b] * dp2[n][m];
    
    return 0;
}