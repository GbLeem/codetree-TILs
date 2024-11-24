#include <iostream>
#include <unordered_map>
using namespace std;

int n;
char board[100];
unordered_map<char, char> lc;
unordered_map<char, char> rc;

//{'.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void preorder(char cur)
{
    cout << cur;
    if(lc[cur])
        preorder(lc[cur]);
    if(rc[cur])
        preorder(rc[cur]);
}

void inorder(char cur)
{
    if(lc[cur])
        inorder(lc[cur]);
    cout<<cur;
    if(rc[cur])
        inorder(rc[cur]);
}

void postorder(char cur)
{
    if(lc[cur])
        postorder(lc[cur]);
    if(rc[cur])
        postorder(rc[cur]);
    cout<<cur;
}

int main() 
{
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
    {
        char p, l, r;
        cin >> p >> l >> r;
        if('A' <= l && l <= 'Z')
            lc[p] = l;
        if('A' <= r && r <= 'Z')
            rc[p] = r;        
    }

    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    

    return 0;
}