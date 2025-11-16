#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{    
    //모두에게 1벌의 옷이 있는 초기 상태
    vector<int> clothes(n + 2, 1);
    
    //여벌 옷을 가져온 학생들
    for(int i = 0; i < reserve.size(); i++)
    {
        clothes[reserve[i]]++;
    }
    
    //옷을 도난당한 학생들
    for(int i = 0; i < lost.size(); i++)
    {
        clothes[lost[i]]--;
    }
    
    //시작부터 끝까지 돌면서
    for(int idx = 1; idx <= n; idx++)
    {
        if(clothes[idx] == 2)
        {
            //앞과 뒤의 인덱스
            int front = idx - 1;
            int back = idx + 1;
            
            //앞 혹은 뒤에 옷을 빌려준다
            if(clothes[front] == 0)
            {
                clothes[idx]--;
                clothes[front]++;
            }
            else if(clothes[back] == 0)
            {
                clothes[idx]--;
                clothes[back]++;
            }
        }
    }
    
    //체육수업을 들을 수 있는 학생의 최댓값
    int answer = 0;
    
    //옷이 있는 학생들 숫자
    for(int idx = 1; idx <= n; idx++)
    {
        if(clothes[idx] >= 1)
        {
            answer++;
        }
    }
    
    return answer;
}
