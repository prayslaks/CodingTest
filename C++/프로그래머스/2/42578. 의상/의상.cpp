#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    unordered_map<string, int> typeCounter;
    
    //타입 별 개수와 타입 종류를 정리한다
    for(int i = 0; i < clothes.size(); i++)
    {
        string target = clothes[i][1];
        if(typeCounter.find(target) == typeCounter.end())
        {
            typeCounter[target] = 1;
        }
        else
        {
            typeCounter[target]++;
        }
    }
    
    //정답 저장
    int answer = 1;
    
    for(pair<string, int> pair : typeCounter)
    {
        //아무것도 입지 않는 선택지가 포함
        answer *= (pair.second + 1);
    }
    
    //아무것도 입지 않는 선택지를 제외
    return answer - 1;
}