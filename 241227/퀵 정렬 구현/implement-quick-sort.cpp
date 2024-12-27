#include <iostream>
using namespace std;

int board[100'002];

int Partition(int board[], int low, int high)
{
    int pivot = board[high];
    int i = low - 1;

    for(int j = low; j < high; ++j)
    {
        if(board[j] < pivot)
        {
            i++;
            swap(board[i], board[j]);
        }
    }
    swap(board[i + 1], board[high]);
    return i + 1;
}

void QuickSort(int board[], int low, int high)
{
    if(low < high)
    {
        int pos = Partition(board, low, high);

        QuickSort(board, low, pos - 1);
        QuickSort(board, pos + 1, high);
    }
}

int main() 
{   
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    QuickSort(board, 0, n - 1);

    for(int i = 0; i < n; ++i)
    {
        cout << board[i] << " ";
    }
    return 0;
}