#include <iostream>
using namespace std;

int n, m, k;
int board[18][18];
int dp1[18][18];
int dp2[18][18];

void Print1()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << dp1[i][j]<<" ";
        }
        cout << '\n';
    }   
}
void Print2()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << dp2[i][j]<<" ";
        }
        cout << '\n';
    }   
}

int main() 
{
    cin >> n >> m >> k;

    //(0, 0) -> (a-1, b-1)
    //(a, b) -> (n-1, m-1)
    int a = n - 1;
    int b = m - 1;

    if(k != 0)
    {
        k -= 1;
        a = k / m;    
        b = k % m;     

        //0 1
        for(int i = a + 1; i < n; ++i)    
        {
            dp2[i][b] = 1;
        }

        for(int i = b + 1; i < m; ++i)    
        {
            dp2[a][i] = 1;
        }

        for(int i = a + 1; i < n; ++i)
        {
            for(int j = b + 1; j < m; ++j)
            {
                dp2[i][j] = dp2[i-1][j] + dp2[i][j-1];
            }
        }           
    }        
    
    dp1[0][0] = 0;
    dp2[a - 1][b - 1] = 0;

    for(int i = 1; i < n; ++i)
    {
        dp1[i][0] = 1;
    }
        
    for(int i = 1; i < m; ++i)    
    {
        dp1[0][i] = 1;
    }
    
    
    // Print1();
    // cout <<"\n";
    // Print2();

    for(int i = 1; i <= a; ++i)
    {
        for(int j = 1; j <= b; ++j)
        {
            dp1[i][j] = dp1[i-1][j] + dp1[i][j-1];
        }
    }
    
    for(int i = a + 1; i < n; ++i)
    {
        for(int j = b + 1; j < m; ++j)
        {
            dp2[i][j] = dp2[i-1][j] + dp2[i][j-1];
        }
    }
    
    //cout << dp1[a][b] << "\n";
    //cout << dp2[n][m] << "\n";
    
    if(dp2[n-1][m-1] != 0)
        cout << dp1[a][b] * dp2[n-1][m-1];
    else
        cout << dp1[a][b];
    
    // cout << "\n";
    // Print1();
    // cout <<"\n";
    // Print2();

    return 0;
}