#include <iostream>
#include <unordered_map>
using namespace std;

int n;
char board[100];
unordered_map<char,int> alpha;
//{'.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void preorder(int cur)
{
    cout << board[cur];
    if(board[cur*2])
        preorder(cur*2);
    if(board[cur*2+1])
        preorder(cur*2+1);
}

void inorder(int cur)
{
    if(board[cur*2])
        inorder(cur*2);
    cout<<board[cur];
    if(board[cur*2+1])
        inorder(cur*2+1);
}

void postorder(int cur)
{
    if(board[cur*2])
        postorder(cur*2);
    if(board[cur*2 + 1])
        postorder(cur*2+1);
    cout<<board[cur];
}

int main() 
{
    char ch = 'A';
    for(int i = 1; i <= 26; ++i)
    {
        alpha[ch] = i;
        ch++;
    }

    cin >> n;
    
    for(int i = 1; i <= n; ++i)
    {
        char p, l, r;
        cin >> p >> l >> r;
        
        int idx = alpha[p];

        board[idx] = p;
        if('A' <= l && l <= 'Z')
        {
            board[idx * 2] = l;
            alpha[l] = idx*2;
        }
        if('A' <= r && r <= 'Z')           
        {
            board[idx * 2 + 1] = r;        
            alpha[r] = idx*2+1;
        } 
    }

    preorder(1);
    cout<<"\n";
    inorder(1);
    cout<<"\n";
    postorder(1);
    

    return 0;
}