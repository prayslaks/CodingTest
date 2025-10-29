#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    //명령은 여러 개
    for(vector<int> command : commands)
    {
        //이번 명령을 처리할 임시 벡터
        vector<int> temp;
        
        //이번 명령을 파싱
        int i = command[0];
        int j = command[1];
        int k = command[2];

        //명령 수행
        for(int idx = i - 1; idx < j; idx++)
        {
            temp.push_back(array[idx]);
        }
        sort(temp.begin(), temp.end());
        int result = temp[k - 1];
        
        //결과 삽입
        answer.push_back(result);
    }
        
    return answer;
}