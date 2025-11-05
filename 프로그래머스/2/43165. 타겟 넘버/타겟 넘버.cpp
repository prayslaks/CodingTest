#include <string>
#include <vector>
#include <iostream>

using namespace std;

//타겟에 도달할 수 있는 답의 개수
int answer = 0;

void dfs(vector<int>& numbers, int& target, int current, int idx)
{
    //모든 패를 소진했을 때
    if(idx >= numbers.size())
    {
        if(current == target)
        {
            //타겟에 도달할 수 있는 패를 찾음
            answer++;
            return;
        }
        else
        {
            //타겟에 도달할 수 있는 패가 아님
            return;
        }
    }
    
    //더하거나 빼는 두 가지 경우의 수에 대해 시도
    dfs(numbers, target, current + numbers[idx], idx + 1);
    dfs(numbers, target, current - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) 
{
    dfs(numbers, target, 0, 0);
    
    return answer;
}