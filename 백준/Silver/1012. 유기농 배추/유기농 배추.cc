#include<iostream>
#include<queue>

using namespace std;

int M, N;
bool cabbage[100][100];
int dw[4]{ 0, 1, 0, -1 };
int dh[4]{ 1, 0, -1, 0 };

int main()
{
    int T;
    cin >> T;

    //테스트
    for (int t = 0; t < T; t++)
    {
        //검색 용
        queue<int> inputs;

        //좌표 정보
        int K;
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            inputs.push(y * M + x);
            cabbage[y][x] = true;
        }

        //그룹 숫자
        int group = 0;

        while(!inputs.empty())
        {
            //벌레가 이동을 시작할 위치
            int next = inputs.front();
            inputs.pop();

            //이미 먹음
            if (cabbage[next / M][next % M] == false)
                continue;

            //예약
            cabbage[next / M][next % M] = false;
            queue<int> reserved;
            reserved.push(next);

            //벌레의 탐색 시행
            while (!reserved.empty())
            {
                //추출
                int search = reserved.front();
                reserved.pop();

                //상하좌우 확인
                for (int i = 0; i < 4; i++)
                {
                    //델타
                    int w = (search % M) + dw[i];
                    int h = (search / M) + dh[i];
                    int target = (h * M) + w;

                    //범위 확인
                    if (w < 0 || w >= M || h < 0 || h >= N)
                        continue;

                    //인접 여부 확인
                    if (cabbage[h][w] == true)
                    {
                        //예약
                        cabbage[h][w] = false;
                        reserved.push(target);
                    }
                }
            }

            //그룹 증가
            group++;
        }

        //그룹 개수
        cout << group << endl;
    }
}