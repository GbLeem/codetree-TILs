#include <iostream>
#include <string>
using namespace std;

int n;
string s_init;

struct Node 
{    
    string data;   
    Node *prev;
    Node *next;
    
    Node(string data) :
    	data(data),
    	prev(nullptr),
    	next(nullptr) {}
};

void InsertPrev(Node* cur, Node* singleton)
{
    singleton->prev = cur->prev;
    singleton->next = cur;

    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void InsertNext(Node* cur, Node* singleton)
{
    singleton->prev = cur;
    singleton->next = cur->next;

    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void Print(Node* cur)
{
    if(cur->prev != nullptr)
        cout << cur->prev->data << " ";
    else 
        cout <<"(Null) ";

    cout << cur->data << " ";
    
    if(cur->next != nullptr)
        cout << cur->next->data;
    else   
        cout <<"(Null)";
    cout << "\n";
}

int main() 
{
    cin >> s_init;
    Node* cur = new Node(s_init);

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int num;
        string s_value;
        cin >> num;

        if(num == 1)
        {
            cin >> s_value;
            Node* node = new Node(s_value);
            InsertPrev(cur, node);

            Print(cur);
        }
        else if(num == 2)
        {
        cin >> s_value;
            Node* node = new Node(s_value);
            InsertNext(cur, node);

            Print(cur);
        }
        else if(num == 3)
        {   
            if(cur->prev != nullptr)
            {
                cur = cur->prev;
            }
            Print(cur);
        }
        else if(num == 4)
        {
            if(cur->next != nullptr)
            {
                cur = cur->next;
            }
            Print(cur);
        }
    }
    return 0;
}