#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    //배포에 성공할 때마다 하나씩 오른다
    //2번이 완료되어도 1번이 아직 완료되지 않았다면 포인터는 움직이지 않는다
    //2번이 완료되었을 때 1번도 완료되어 있다면 포인터는 2번까지 한번에 움직인다
    //그러면 이제 포인터는 3번부터 작업이 완료되었는지 확인한다
    int pointer = 0;
    
    for(int day = 1;; day++)
    {
        //작업 진행
        for(int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
            progresses[i] = progresses[i] > 100 ? 100 : progresses[i];
        }
            
        //오늘 몇 개의 작업을 완료했는지 카운트한다
        int today = 0;
        
        while(pointer < progresses.size())
        {
            //완료한 작업은 배포하고 나면 신경 쓸 필요 없으므로 포인터가 영구 상승한다
            if(progresses[pointer] >= 100)
            {
                pointer++;
                today++;
            }
            else
            {
                //앞 작업이 끝나지 않았는지 뒷 작업을 확인할 필요가 없다
                break;
            }
        }
        
        //오늘 1개 이상의 작업을 완료했다면
        if(today > 0)
        {
            answer.push_back(today);   
        }
        
        //모든 작업을 수행했으므로 종료
        if(pointer >= progresses.size())
        {
            break;
        }
    }
    
    return answer;
}