#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) 
{
    int answer = 0;
    
    int length = name.length();

    // 수평 전체 이동 최솟값
    int minMove = length - 1;
    
    for(int i = 0; i < length; i++)
    {
        // 수직 이동 최솟값 합산
        int up = name[i] - 'A';
        int down = 26 - up;
        answer += min(up, down);
        
        // 위치에서 i에서 다음 목표 next는
        int next = i + 1;
        while(next < name.length() && name[next] == 'A')
        {
            next++;
        }
        
        // i까지 온 이후 next에 도달하는 두 가지 전략
        minMove = min(minMove, i * 2 + (length - next));
        minMove = min(minMove, (length - next) * 2 + i);
    }
    
    // 수평 이동 최솟값 합산
    answer += minMove;
    return answer;
}