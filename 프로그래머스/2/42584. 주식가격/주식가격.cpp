#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size(), 0);
    
    // 정확히는 구입 시점에서 음전하지 않은 기간의 길이
    // 하락만 했다면 1으로 도배
    // 상승만 했다면 내림차순
    
    stack<int> s;
    for(int i = 0; i < prices.size() - 1; i++)
    {
        int curr = prices[i];
        int next = prices[i + 1];
        if(curr <= next)
        {
            s.push(i);
        }
        else
        {
            answer[i] = 1;
            while(s.empty() == false)
            {
                // 음전이 발생했다면
                if(prices[s.top()] > next)
                {
                    // 기간을 연산한다
                    answer[s.top()] = i + 1 - s.top();
                    s.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    int len = prices.size() - 1;
    while(s.empty() == false)
    {
        answer[s.top()] = len - s.top();
        s.pop();
    }
    
    return answer;
}