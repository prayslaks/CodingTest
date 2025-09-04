#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int pointer = 0;
    for(int day = 1;; day++)
    {
        //작업 진행
        for(int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
            progresses[i] = progresses[i] > 100 ? 100 : progresses[i];
        }
            
        //0번부터 확인
        int today = 0;
        while(pointer < progresses.size())
        {
            if(progresses[pointer] >= 100)
            {
                pointer++;
                today++;
            }
            else
            {
                break;
            }
        }
        
        if(today > 0)
            answer.push_back(today);
        
        if(pointer >= progresses.size())
            break;
    }
    
    return answer;
}