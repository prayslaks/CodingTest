#include<iostream>
#include<vector>

using namespace std;

//사람의 숫자
int N;

//인접 리스트
vector<vector<int>> frList;

//확인 여부를 저장하여 순환 방지
bool visited[2000];

//종료 신호
bool stop = false;

bool dfs(int point, int len)
{
    //조건을 만족하는 친구 길이
    if (len >= 5)
        return true;

    //순환 방지
    visited[point] = true;

    //인접 리스트 순회
    for (int target : frList[point])
    {
        //자기 자신은 건너뛰기
        if (target == point)
            continue;

        //친구 관계 확인
        if (visited[target] == false)
        {
            //다음 친구로 넘어가 반복
            if (dfs(target, len + 1))
            {
                //이전 함수에 성공 상태 전달
                return true;
            }
        }
    }

    //더 이상 사용하지 않는 경로이니 무효화
    visited[point] = false;

    //이전에 방문하지 않았던 새로운 친구 없음
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        frList.push_back(temp);
    }

    for (int i = 0; i < M; i++)
    {
        //친구관계 입력
        int a, b;
        cin >> a >> b;
        frList[a].push_back(b);
        frList[b].push_back(a);
    }

    bool result = false;
    for (int num = 0; num < N; num++)
    {
        //성공했으므로 조기 종료
        if (dfs(num, 1))
        {
            result = true;
            break;
        }
    }

    //결과 출력
    cout << result;
}