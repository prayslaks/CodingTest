#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    //큐
    queue<int> temp;

    //하나 삽입
    temp.push(arr[0]);

    //하나씩 삽입
    for(int i = 1; i < arr.size(); i++)
    {
        if(temp.back() != arr[i])
        {
            temp.push(arr[i]);
        }
    }
    
    //반환용
    vector<int> answer;

    //전부 이동
    while(!temp.empty())
    {
        answer.push_back(temp.front());
        temp.pop();
    }

    return answer;
}