#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(true)
    {
        //지갑에 들어갈 수 있는지 확인
        bool check1 = wallet[0] >= bill[0] && wallet[1] >= bill[1];
        bool check2 = wallet[0] >= bill[1] && wallet[1] >= bill[0];
        if(check1 || check2)
            break;
        
        //더 긴 방향으로 접기
        if(bill[0] > bill[1])
            bill[0] /= 2;
        else
            bill[1] /= 2;
        answer++;
    }
    
    return answer;
}