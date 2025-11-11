#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    
    //정렬
    sort(citations.begin(), citations.end());
    
    //큰 H-Index부터 시도
    for(int h = citations.size(); h >= 0; h--)
    {
        //h보다 인용 횟수가 크거나 같은 논문의 갯수
        int count = 0;
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] >= h)
            {
                count++;
            }
        }
        
        //조건을 만족하는 논문의 개수가 h보다 크거나 같다면
        if(count >= h)
        {
            answer = h;
            break;
        }
    }
    
    return answer;
}