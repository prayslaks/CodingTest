#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    //t초 동안 붕대를 감는다
    //1초마다 x만큼 체력 회복
    //t초 연속 성공하면 y를 추가 회복
    //최대 체력이 있어서 그거보다 커지지는 않음
    //공격 당하면 그 순간은 체력 x회복 안되고, 연속 기록이 끊김
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    int chain = 1;
    
    //현재 공격
    int current = 0;
    vector<int> attack = attacks[current];
    
    //최대 체력
    int maxHealth = health;
    
    for(int i = 1;; i++)
    {
        if(i == attack[0])
        {
            //공격 발생
            health -= attack[1];
            
            //죽음
            if(health <= 0)
                return -1;
            
            //체인 초기화
            chain = 1;
            
            //마지막 공격 종료
            if(++current == attacks.size())
                break;
            
            //다음 공격으로
            attack = attacks[current];
        }
        else
        {
            //회복 발생
            health += x;
            
            //회복 체인
            chain++;
            
            //추가 회복
            if(chain > t)
            {
                health += y;
                chain = 1;    
            }
            
            //최대 체력
            if(health > maxHealth)
                health = maxHealth;
        }
    }
    
    return health;
}