#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> vec;
vector<int> ans;
int isused[1002];
int answer = 0;

void Print()
{
	for (auto a : ans)
	{
		cout << a << " ";
	}
	cout << "\n";
}

int Count()
{
	int temp = 1;
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		int x2 = vec[ans[i]].second;
		int newx1 = vec[ans[i + 1]].first;

		if (newx1 > x2)
			temp++;
	}
	return temp;
}

void Choose(int cur)
{
	if (ans.size() >= 2)
		answer = max(answer, Count());

	for (int i = 0; i < n; ++i)
	{
		//중복 제거
		if (!isused[i])
		{
			if (ans.empty() || i > ans.back())
			{
				ans.push_back(i);
				isused[i] = 1;
				Choose(cur + 1);
				ans.pop_back();
				isused[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x1, x2;
		cin >> x1 >> x2;

		vec.push_back({ x1, x2 });
	}

	sort(vec.begin(), vec.end());

	Choose(1);

	cout << answer;
	return 0;
}