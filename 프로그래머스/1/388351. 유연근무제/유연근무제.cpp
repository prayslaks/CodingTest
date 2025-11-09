#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    
    //토요일과 일요일은 신경쓰지 않아도 좋다
    //시작 요일은 언제일지 모르므로 토요일과 일요일을 인지하는 로직 필요
    
    for(int i = 0; i < timelogs.size(); i++)
    {
        //i번째 직원의 출근 로그에 접근
        vector<int> timelog = timelogs[i];
        
        //상품 여부
        bool prize = true;
        
        //목표 시간
        int target = schedules[i];
        int targetHour = target / 100;
        int targetMinute = target % 100;
        int targetReconst = targetHour * 60 + targetMinute;
        
        //한 바퀴 돌 때까지
        int counter = 0;
        for(int day = startday - 1; counter < 7; day++)
        {
            cout << "오늘은 " << day + 1 << "요일입니다" << endl;
            
            //토요일과 일요일은 건너뛴다
            if((day % 7) == 5 || (day % 7) == 6)
            {
                counter++;
                continue;
            }
            
            //출근 시간
            int attend = timelog[counter];
            int attendHour = attend / 100;
            int attendMinute = attend % 100;
            int attendReconst = attendHour * 60 + attendMinute;
            
            cout << attendReconst << " " << targetReconst << endl;
            
            if(attendReconst - targetReconst > 10)
            {
                prize = false;
                cout << "실패" << endl;
                break;
            }
               
            counter++;
        }
        
        //상을 받을 자격이 있음
        if(prize)
        {
            cout << "통과" << endl;
            answer++;
        }
    }
    
    
    return answer;
}