#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    
    //0을 원점으로하는 xy 좌표계를 가정
    pair<int, int> posL = make_pair(-1, 0);
    pair<int, int> posR = make_pair(1, 0);
    
    //번호를 좌표로 사상하는 벡터
    vector<pair<int, int>> posVec = 
    {
        { 0, 0 },
        { -1, 3 },
        { 0, 3 },
        { 1, 3 },
        { -1, 2 },
        { 0, 2 },
        { 1, 2 },
        { -1, 1 },
        { 0, 1 },
        { 1, 1 },
    };
    
    for(int i = 0; i < numbers.size(); i++)
    {
        //이번에 눌러야 하는 숫자
        int target = numbers[i];
        
        if(target == 1 || target == 4 || target == 7)
        {
            answer += "L";
            posL = posVec[target];
        }
        else if(target == 3 || target == 6 || target == 9)
        {
            answer += "R";
            posR = posVec[target];
        }       
        else
        {
            //목표의 xy 좌표
            int first = posVec[target].first;
            int second = posVec[target].second;
            
            //목표와 좌엄지 우엄지 간의 거리
            int disL = abs(posL.first - first) + abs(posL.second - second);
            int disR = abs(posR.first - first) + abs(posR.second - second);
            
            //거리 비교
            if(disL < disR)
            {
                answer += "L";
                posL = posVec[target];
            }
            else if(disL > disR)
            {
                answer += "R";
                posR = posVec[target];
            }
            else
            {
                if(hand == "left")
                {
                    answer += "L";
                    posL = posVec[target];
                }
                else
                {
                    answer += "R";
                    posR = posVec[target];                
                }
            }
        }
    }
    
    return answer;
}