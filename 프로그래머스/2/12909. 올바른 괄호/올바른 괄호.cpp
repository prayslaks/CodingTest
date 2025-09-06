#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    //값이 0이면 짝이 맞는 상태
    int count = 0;
    
    //순회
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            //열린 괄호 카운트
            count++;
        }
        else
        {
            //열린 괄호가 없는데 닫으려 시도
            if(count == 0)
            {
                return false;
            }
            
            //닫힌 괄호 카운트
            count--;
        }
    }

    return (count == 0 ? true : false);
}