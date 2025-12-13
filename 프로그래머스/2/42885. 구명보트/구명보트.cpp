#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    // 오름차순 정렬
    sort(people.begin(), people.end());
    
    // 1개 배 작업 중
    int answer = 0;
    
    // 왼쪽과 오른쪽 양 끝에서 시작
    int left = 0;
    int right = people.size() - 1;
    while(left <= right)
    {
        // 무게
        int w1 = people[left];
        int w2 = people[right];
        
        // 가능한 최선의 결과
        if(w1 + w2 <= limit)
        {
            left++;;
        }
        
        // 무거운 쪽은 어차피 탄다
        right--;

        // 구명보트 추가
        answer++;
    }
    
    return answer;
}