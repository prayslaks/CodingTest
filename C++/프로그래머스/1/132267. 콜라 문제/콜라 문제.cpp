#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
   
    //교환이 가능한 동안
    while(a <= n)
    {
        //새로 받은 콜라
        int exchange = b * (n / a);
        
        //답 업데이트
        answer += exchange;
        
        //교환 받지 못한 빈 콜라
        int left = n % a;
        
        //다음 단계 빈 콜라
        n = exchange + left;
    }
    
    //그동안 반환 받은 총 콜라의 개수
    return answer;
}