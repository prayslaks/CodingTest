#include <iostream>
#include <queue>

using namespace std;

bool graph[101][101];
bool infection[101];

int main()
{
    int N;
    cin >> N;

    int pairNum;
    cin >> pairNum;
    for (int i = 0; i < pairNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
   
    //바이러스 시작점
    int start = 1;
    infection[start] = true;
    int count = 0;

    //다음 전파 대상
    queue<int> near;
    near.push(start);
    
    //최대한 감염시킬 때까지
    while (!near.empty())
    {
        //다음 대상
        int next = near.front();
        near.pop();

        //자신과 연결되어있는 컴퓨터 검색
        for (int i = 1; i <= N; i++)
        {
            //자기 자신은 건너뛰기
            if (i == next)
                continue;

            //아직 감염 안 됨 & 이동 가능
            if (infection[i] == false && graph[next][i] == true)
            {
                //감염
                infection[i] = true;
                count++;

                //다음
                near.push(i);
            }
        }
    }

    //출력은 1번 컴퓨터를 통해 감염된 컴퓨터의 숫자다
    cout << count << endl;
}