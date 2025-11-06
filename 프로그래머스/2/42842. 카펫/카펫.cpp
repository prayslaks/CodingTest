#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    for(int x = yellow; x >= 1; x--)
    {
        //깔끔하게 나눠떨어져야 한다
        if(yellow % x != 0)
        {
            continue;
        }
        
        //세로 길이
        int y = yellow / x;
        
        //갈색 숫자
        int brownCount = (y * 2) + ((x + 2) * 2);
        
        //정답을 찾았다면
        if(brown == brownCount)
        {
            answer.push_back(x + 2);
            answer.push_back(y + 2);
            return answer;
        }
    }
    
    return answer;
}