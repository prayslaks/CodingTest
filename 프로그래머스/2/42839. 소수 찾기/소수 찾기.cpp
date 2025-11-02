#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

//DFS용 
bool visited[7];

//입력을 옮겨 넣는 전역 변수
string target;

//탐색한 조합 저장
vector<string> combination;

//유일성 확인용
unordered_map<string, bool> map;

void dfs(string before, int idx)
{   
    if(idx >= target.length())
        return;
    
    for(int i = 0; i < target.length(); i++)
    {
        if(visited[i] == false)
        {
            //마킹
            visited[i] = true;
            
            //유일성 보장
            string temp = before + target[i];
            if(map.find(temp) == map.end())
            {
                cout << temp << endl;
                map[temp] = true;
                combination.push_back(temp);
            }

            //재귀
            dfs(temp, idx + 1);
            
            //백트래킹
            visited[i] = false;
        }
    }
}

bool prime(int num)
{
    if(num <= 1)
        return false;
    
    if(num % 2 == 0)
        return num == 2 ? true : false;
    
    for(int i = 3; i * i <= num; i += 2)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    
    //전역 변수로 옮김
    target = numbers;
    
    //모든 조합을 탐색하여 배열에 저장
    dfs("", 0);
    
    for(int i = 0; i < combination.size(); i++)
    {
        //맨 앞이 0이면 건너뛰기
        if(combination[i][0] == '0')
            continue;
        
        //소수 여부를 확인
        if(prime(stoi(combination[i])))
        {
            //카운트 증가
            answer++;
        }
    }
    
    return answer;
}