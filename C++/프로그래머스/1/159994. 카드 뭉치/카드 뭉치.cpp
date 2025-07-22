#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    //목적 문장
    int count = goal.size();
    
    //각각의 카드 더미
    int pointer1 = 0;
    int pointer2 = 0;
    
    //목적 문장을 완성할 때까지
    for(int cnt = 0; cnt < goal.size(); cnt++)
    {
        if(goal[cnt] == cards1[pointer1])
        {
            //1번과 일치
            pointer1++;
        }
        else if(goal[cnt] == cards2[pointer2])
        {
            //2번과 일치
            pointer2++;
        }
        else
        {
            //1번과 2번 중에 어떤 곳에서도 필요한 카드 없음
            return "No";
        }
    }
    
    //무사히 완료했다면 완성했다는 의미
    return "Yes";
}