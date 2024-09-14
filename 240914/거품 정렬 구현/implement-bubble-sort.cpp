#include <iostream>
#include <algorithm>
using namespace std;

int arr[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    while(1)
    {    
        int cnt = 0;            
        for(int i = 0; i < n - 1; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            } 
            else
                cnt++;
        }          
        if(cnt == n - 1)
            break;
    }

    for(int i = 0; i < n; ++i)
        cout << arr[i]<<" ";

    return 0;
}