#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) 
{    
    //(프로세스 번호, 우선순위) 큐
    queue<pair<int, int>> task;
    
    //(우선순위, 프로세스 개수) 배열
    vector<int> table(10, 0);
    
    //큐에 있는 것들 중 가장 높은 우선 순위
    int high = 0;
    
    //프로세스 번호
    int process = 0;
    for(int p : priorities)
    {
        //순서대로 큐에 삽입
        task.push(make_pair(process++, p));
        
        //우선순위-개수 테이블 갱신
        table[p]++;
        
        //최고 우선순위 갱신
        if(high < p)
        {
            high = p;
        }
    }
    
    //시간
    int time = 1;
    
    //큐가 차있는 동안
    while(task.empty() == false)
    {
        //최고 우선순위를 가진 작업 전부 소모
        if(table[high] <= 0)
        {
            //우선순위를 하나 낮춰서 시도하기로 결정
            high--;
            
            //다음으로
            continue;
        }
        
        //맨 앞에 있는 값
        pair<int, int> temp = task.front();
        
        cout << "이번 프로세스 " << temp.first << endl;
        
        //추출
        task.pop();
        
        //최고 우선순위보다 작으면
        if(temp.second < high)
        {
            //뒤로 보낸다
            task.push(temp);
            
            //다음으로
            continue;
        }
        
        //최고 우선순위와 같으면
        if(temp.second == high)
        {
            //목표 프로세스에 도달함
            if(location == temp.first)
            {
                break;
            }
            
            //실행한다
            table[temp.second]--;
            
            //시간 증가
            time++;
            
            //다음으로
            continue;
        }
        
    }

    return time;
}