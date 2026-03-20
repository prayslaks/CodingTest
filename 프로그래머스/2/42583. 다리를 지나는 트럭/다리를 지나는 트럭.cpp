#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    // 다리
    queue<int> bridge;
    for(int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }
     
    int truck = 0;
    int time = 0;
    int pressure = 0;
    int count = 0;
    for(time = 1;; time++)
    {
        // 탈출
        if(bridge.front() > 0)
        {
            pressure -= bridge.front();
            count++;
        }
        bridge.pop();
        
        // 종료
        if(count >= truck_weights.size())
        {
            break;
        }
        
        // 진입
        if(pressure + truck_weights[truck] <= weight)
        {
            // 다리 제일 끝에 투입
            bridge.push(truck_weights[truck]);
            pressure += truck_weights[truck++];
        }
        else
        {
            // 빈 공간
            bridge.push(0);    
        }
    }
    
    return time;
}