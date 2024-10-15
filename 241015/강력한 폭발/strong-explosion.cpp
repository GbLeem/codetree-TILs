#include <iostream>
#include <vector>
using namespace std;

int board[22][22];
int n;
int bomb = 0;
vector<int> ans;
vector<pair<int,int>> pos;
int answer = 0;

bool InRange(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < n);
}

int Count()
{
	int tempBoard[25][25];
	int temp = 0;

    for(int i = 0; i < 25; ++i)    
        fill(tempBoard[i], tempBoard[i] + 25, 0);
    
	for (int i = 0; i < pos.size(); ++i) //모든 위치
	{		
		int x = pos[i].first;
		int y = pos[i].second;

		if (ans[i] == 0)
		{
			tempBoard[x][y] = 1;
			tempBoard[x - 1][y] = 1;
			tempBoard[x - 2][y] = 1;
			tempBoard[x + 1][y] = 1;
			tempBoard[x + 2][y] = 1;

		}
		else if (ans[i] == 1)
		{
			tempBoard[x][y] = 1;
			tempBoard[x - 1][y] = 1;
			tempBoard[x + 1][y] = 1;
			tempBoard[x][y + 1] = 1;
			tempBoard[x][y - 1] = 1;
		}
		else if (ans[i] == 2)
		{
			tempBoard[x][y] = 1;
			tempBoard[x - 1][y + 1] = 1;
			tempBoard[x + 1][y + 1] = 1;
			tempBoard[x + 1][y - 1] = 1;
			tempBoard[x - 1][y - 1] = 1;
		}		
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (tempBoard[i][j] == 1)
				temp++;
		}
	}

	return temp;
}

void Print()
{
	for (auto a : ans)
	{
		cout << a << " ";
	}
	cout << "\n";
}

void Choose(int cur)
{
	if (cur == bomb + 1)
	{
		answer = max(answer, Count());				    
		return;
	}
	
	for (int i = 0; i < 3; ++i)
	{
		ans.push_back(i);
		Choose(cur + 1);
		ans.pop_back();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				bomb++;
				pos.push_back({ i, j });
			}			
		}
	}

	Choose(1);

	cout << answer;
}