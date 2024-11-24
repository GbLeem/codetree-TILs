#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k;
int inorder[2002];
int origin[2002];
//vector<int>origin;

void makeTree(int idx, int st, int en)
{
    if(st > en)
        return;
    int mid = (st+en)/2;
    //origin.push_back(inorder[mid]);
    origin[idx] = inorder[mid];
    makeTree(idx*2, st, mid-1);
    makeTree(idx*2+1, mid+1, en);
}

void level()
{

}
int main() 
{
    cin >> k; //2^k-1개
    int total = pow(2,k)-1;
    for(int i = 1; i <= total; ++i)
    {
        cin >> inorder[i];
    }
    makeTree(1, 1, total);

    int count = 0;
    int temp = 0;
    for(int i = 1; i <= total; ++i)
    {
        cout << origin[i]<<" ";
        temp++;
        if(temp == pow(2, count))
        {
            temp = 0;
            count++;
            cout << '\n';
        }
    }

    return 0;
}