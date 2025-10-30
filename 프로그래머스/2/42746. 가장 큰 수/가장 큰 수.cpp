#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{    
    string answer = "";
    
    //모든 숫자를 문자열로 변환
    vector<string> temp;
    for(int number : numbers)
    {
        temp.push_back(to_string(number));
    }
    
    //커스텀 함수를 사용한 비교 정렬
    sort(temp.begin(), temp.end(), compare);
    
    //0밖에 없는 상황
    if(temp[0] == "0")
    {
        return "0";
    }
    
    //종합
    for(string str : temp)
    {
        answer += str;
    }
    
    return answer;
}