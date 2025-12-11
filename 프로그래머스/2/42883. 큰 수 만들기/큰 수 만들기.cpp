#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) 
{
    stack<char> stack;
    for(int i = 0; i < number.length(); i++)
    {
        // 이번에 확인해볼 값
        char value = number[i];
        
        // 가능한 만큼 값을 스택 깊은 곳에 넣는다
        while(stack.empty() == false && stack.top() < value && k > 0)
        {
            stack.pop();
            k--;  
        }
        stack.push(value);
    }
    
    // 남은 수 만큼 제거
    while (k > 0)
    {
        stack.pop();
        k--;  
    }
    
    // 문자열을 반대로 뒤집는다
    string answer = "";
    while(stack.empty() == false)
    {
        answer += stack.top();
        stack.pop();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}