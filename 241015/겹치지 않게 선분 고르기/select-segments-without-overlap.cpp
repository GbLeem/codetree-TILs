#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;
vector<int> ans;
int n;

void Print()
{
	for(auto a : ans)
	{
		cout << a <<" ";
	}
	cout <<"\n";
}

int Count()
{
	int cnt = 1;
	for(int i = 0; i < ans.size(); ++i)
	{
		int nextx1 = vec[ans[i+1]].first;		
		int x2 = vec[ans[i]].second;

		if(nextx1 > x2)
		{
			cnt++;
		}
	}	
	//cout << cnt <<"\n";
	return cnt;
}
int answer = 0;
void Choose(int cur)
{
	if(cur == n + 1)
	{
		//Print();
		answer = max(answer, Count());
		return;
	}

	for(int i = 0; i < vec.size(); ++i)
	{
		ans.push_back(i);
		Choose(cur + 1);
		ans.pop_back();
	}
}

int main() 
{
    cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int x1, x2;
		cin >> x1 >> x2;

		vec.push_back({x1, x2});
	}

	sort(vec.begin(), vec.end());

	Choose(1);

	cout<<answer;

    return 0;
}