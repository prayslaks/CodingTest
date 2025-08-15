#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int k;
    cin >> k;

    int low = 1;
    int high = k;
    int mid;
    int res;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        //전체 중에서 mid보다 작은 수의 개수를 구한다
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(N, mid / i);
        }

        if (cnt >= k)
        {
            //결과를 저장하고 다음으로
            res = mid;

            //더 작은 구역
            high = mid - 1;
        }
        else
        {
            //더 높은 구역
            low = mid + 1;
        }
    }

    cout << res << endl;
}