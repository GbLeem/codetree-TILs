#include <iostream>
using namespace std;

class Boom
{
public:
    string code;
    char color;
    int seconds;

    Boom(string _code, char _color, int _seconds)
        :code(_code)
        ,color(_color)
        ,seconds(_seconds)
    {}
};

int main() 
{
    string s;
    char c;
    int i;
    cin >> s >> c >> i;
    Boom boom(s,c,i);

    cout <<"code : "<<boom.code<<"\n";
    cout <<"color : "<<boom.color<<"\n";
    cout <<"second : "<<boom.seconds<<"\n";    
    return 0;
}