#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    //p의 길이
    int pLen = p.length();
    
    //자를 수 있는 범위까지
    for(int i = 0; i <= t.length() - pLen; i++)
    {
        //부분 문자열
        string sub = t.substr(i, pLen);
        
        //비교
        int check = 1;
        for(int j = 0; j < pLen; j++)
        {
            if(sub[j] < p[j])
            {
                //더 이상 확인할 필요 없음
                break;
            }
            else if(sub[j] == p[j])
            {
                //다음 자리도 한 번 봐야함
                continue;
            }
            else
            {
                //더 이상 확인할 필요 없음
                check = 0;
                break;
            }
        }
        
        //확인 결과를 업데이트
        answer += check;
    }
    
    return answer;
}