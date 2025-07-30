#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N;
int house[100][100];
int dw[4]{ 0, 1, 0, -1 };
int dh[4]{ 1, 0, -1, 0 };
vector<int> group_count;

int main()
{
    //검색 용
    queue<int> cord;

    //좌표 정보
    cin >> N;
    cin.ignore();

    //문자열 정보를 변환
    for (int i = 0; i < N; i++)
    {
        string input;
        getline(cin, input);

        for (int j = 0; j < input.length(); j++)
        {
            house[i][j] = input[j] - '0';
            if (house[i][j] == 1)
            {
                cord.push(i * N + j);
            }
        }
    }

    //바닥날 때까지
    while (!cord.empty())
    {
        //그룹 숫자
        int count = 0;

        //이동을 시작할 위치
        int next = cord.front();
        cord.pop();

        //이미 그룹이 있거나 원래부터 없던 곳
        if (house[next / N][next % N] == 0)
            continue;

        //예약
        house[next / N][next % N] = 0;
        queue<int> reserved;
        reserved.push(next);

        //탐색 시행
        while (!reserved.empty())
        {
            //추출
            int search = reserved.front();
            reserved.pop();

            //상하좌우 확인
            for (int i = 0; i < 4; i++)
            {
                //델타
                int w = (search % N) + dw[i];
                int h = (search / N) + dh[i];
                int target = (h * N) + w;

                //범위 확인
                if (w < 0 || w >= N || h < 0 || h >= N)
                    continue;

                //인접 여부 확인
                if (house[h][w] == 1)
                {
                    //예약
                    house[h][w] = 0;
                    reserved.push(target);
                }
            }

            //그룹 증가
            count++;
        }

        //그룹 개수
        group_count.push_back(count);
    }

    //정렬
    sort(group_count.begin(), group_count.end());

    //그룹 개수
    cout << group_count.size() << endl;

    //출력
    for (int g : group_count)
    {
        cout << g << endl;
    }
}