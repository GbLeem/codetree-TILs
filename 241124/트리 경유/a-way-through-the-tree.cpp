#include <iostream>
#include <climits>
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
            //올라가다가 못가는 곳 만남
            if(vis[temp])
            {
                //가장 위의 불가능 노드 찾기
                int minValue = INT_MAX;
                while(temp != 1)
                {           
                    if(vis[temp] == 1)
                        minValue = min(minValue, temp);         
                    temp/=2;
                }
                cout << minValue <<"\n";
                break;
            }            
            //루트 도착
            else if(temp == 1)
            {
                cout << 0 << "\n";
                vis[dest] = 1;  
                break;
            }
            temp /= 2;
        }           
    }

    return 0;
}