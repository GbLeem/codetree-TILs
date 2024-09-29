#include <iostream>
using namespace std;

int main() 
{
    int n;
    string str;

    cin >> n;
    cin >> str;

    int answer = 0;
    for(int i = 0; i < n; ++i)
    {
        if(str[i] == 'C')
        {
            for(int j = i+1; j < n;++j)
            {
                if(str[j] == 'O')
                {
                    for(int k = j+1; k<n; ++k)
                    {
                        if(str[k] == 'W')
                        {
                            answer++;
                        }
                    }
                }
            }
        }   
    }
    
    cout << answer;
    return 0;
}