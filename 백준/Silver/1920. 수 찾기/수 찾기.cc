#include<iostream>
#include<algorithm>

using namespace std;

int A[100001];
int main()
{
    //데이터 입력
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    //정렬
    sort(A, A + N);

    //쿼리
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int temp;
        scanf("%d", &temp);

        //이진탐색
        int low = 0;
        int high = N - 1;
        while (true)
        {
            //탐색 실패
            if (low > high)
            {
                printf("%d\n", 0);
                break;
            }

            //구간 정의
            int mid = low + (high - low) / 2;
            if (A[mid] == temp)
            {
                printf("%d\n", 1);
                break;
            }
            else if (A[mid] < temp)
            {
                low = mid + 1;
            }
            else if (A[mid] > temp)
            {
                high = mid - 1;
            }
        }
    }
}