#include <string>
#include <vector>
#include <iostream>

using namespace std;

string AEIOU = "AEIOU";
int place = 0;
int answer = -1;

void dfs(string construct, int depth, const string& word)
{    
    // 목표 확인
    if(construct == word)
    {
        answer = place;
    }
    
    // 최대 심도
    if(depth >= 5)
    {
        return;
    }
    
    // DFS로 목표 탐색
    for(int i = 0; i < 5; i++)
    {
        construct.append(1, AEIOU[i]);
        place++;
        dfs(construct, depth + 1, word);
        construct.erase(construct.size() - 1, 1);
    }
}

int solution(string word) 
{
    dfs("", 0, word);
    return answer;
}