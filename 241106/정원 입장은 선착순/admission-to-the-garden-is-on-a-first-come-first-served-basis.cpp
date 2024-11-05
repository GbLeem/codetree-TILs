#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int timeBoard[100'002]; //기다린 시간 저장

struct cmp
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        if (get<0>(a) == get<0>(b))
        {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    }
};

struct cmp2
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<1>(a) > get<1>(b);
    }
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp > pq;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp2 > waitingPQ; //인덱스로만 줄세우기
queue<tuple<int, int, int>> garden;


void Print()
{
    while (!pq.empty())
    {
        auto t = pq.top();
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
        pq.pop();
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a, t;
        cin >> a >> t;

        //먼저 도착한 순서, 번호표 순서로 정렬 되어있음
        pq.push({ a, i + 1, t });
    }

    //시간이 흘러감
    int curTime = 1;
    bool waiting = false;
    int outTime = 0;

    while (1)
    {
        auto topValue = pq.top();

        if (curTime == get<0>(topValue))
        {
            pq.pop();

            if (garden.empty())
            {
                garden.push(topValue);
                timeBoard[get<1>(topValue)] = 0;
                outTime = curTime + get<2>(topValue);
            }

            else
            {
                waitingPQ.push(topValue);
            }
        }

        if (curTime == outTime)
        {
            if(!garden.empty())
                garden.pop();
            if (!waitingPQ.empty())
            {
                auto topWaitingPQvalue = waitingPQ.top();
                garden.push(topWaitingPQvalue);
                waitingPQ.pop();
                timeBoard[get<1>(topWaitingPQvalue)] = curTime - get<0>(topWaitingPQvalue);
                outTime = curTime + get<2>(topWaitingPQvalue);
            }
        }
        curTime++;

        if (pq.empty() && waitingPQ.empty())
            break;
    }

    cout << *max_element(timeBoard + 1, timeBoard + n + 1);
    return 0;
}