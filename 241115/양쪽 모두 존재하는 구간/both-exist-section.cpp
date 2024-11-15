#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100000
#define MAX_M 100000

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_N + 1];
int count_array_in[MAX_M + 1];  // 구간 내 숫자 정보
int count_array_out[MAX_M + 1]; // 구간 외 숫자 정보

int distinct_num_in;  // 구간 내 서로 다른 숫자 개수
int distinct_num_out; 

void Push(int idx)
{
    int num = arr[idx];

    if(count_array_in[num]==0)
        distinct_num_in++;
    count_array_in[num]++;

    count_array_out[num]--;
    if(count_array_out[num] == 0)
        distinct_num_out--;
}

void Pop(int idx)
{
    int num = arr[idx];

    count_array_in[num]--;
    if(count_array_in[num] == 0)
        distinct_num_in--;

    if(count_array_out[num] == 0)
        distinct_num_out++;
    count_array_out[num]++;

}
int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    //범위 나누기 전 전체 체크
    for(int i = 1; i <= n; ++i)
    {
        //처음일때는 갯수 추가        
        if(count_array_out[arr[i]] == 0)
            distinct_num_out++;
        count_array_out[arr[i]]++;
    }
    
    int ans = INT_MAX;

    int j = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(j + 1 <= n && distinct_num_in < m)
        {
            Push(j + 1);
            j++;
        }

        //st 잡고 끝까지 갔는데 못찾은 경우
        if(distinct_num_in < m)
            break;

        if(distinct_num_out == m)
            ans = min(ans, j - i + 1);
        
        Pop(i);
    }

    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}