#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    for(int length : mats)
    {   
        //매트의 크기가 공원의 크기보다 크다
        if(length > park.size() || length > park[0].size())
            continue;
        
        for(int i = 0; i <= park.size() - length; i++)
        {   
            for(int j = 0; j <= park[i].size() - length; j++)
            {
                //배치 가능 여부
                bool check = true;
                
                //확인
                for(int k = i; k < i + length; k++)
                    for(int v = j; v < j + length; v++)
                        if(park[k][v] != "-1")
                            check = false;
            
                //업데이트
                if(check && answer < length)
                {
                    answer = length;
                    break;
                }
            }
        }
    }
    
    return answer == 0 ? -1 : answer;
}