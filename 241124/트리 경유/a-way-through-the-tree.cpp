#include <iostream>
using namespace std;

int n, q;
int vis[2'000'002];

int main() 
{
    cin >> n >> q;

    for(int i = 0; i < q; ++i)
    {
        int dest;
        cin >> dest;
        int temp = dest;
        
        bool fail = false;
        
        //루트 까지 가기
        while(1)
        {   
            if(temp == 1)
            {
                cout << 0 << "\n";
                vis[dest] = 1;  
                break;
            }
            temp /= 2;

            //올라가다가 못가는 곳 만남
            if(vis[temp])
            {
                cout << temp <<"\n";
                fail = true;
                break;    
            }            
        }           
    }

    return 0;
}