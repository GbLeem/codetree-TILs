#include <iostream>
using namespace std;

int arr[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin>> arr[i];
    }

    for(int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for(int j = i; j < n; ++j)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;            
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }


    for(int i = 0; i < n; ++i)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}