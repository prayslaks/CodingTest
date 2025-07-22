#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> umap;
    
    //선수를 해시맵에 등록
    for (int i = 0; i < players.size(); i++) 
    {
        //이름을 키로 현재 등수가 값으로
        umap[players[i]] = i;
    }

    for (auto call : callings) {
        //추월 선수의 등수
        int idx = umap[call];
        
        //두 선수의 위치 교환
        swap(players[idx], players[idx - 1]);
        
        //교환된 등수로 업데이트
        umap[players[idx]] = idx;       
        umap[players[idx - 1]] = idx - 1;
    }
    
    //모든 call을 처리하면 최종 등수대로 이름이 남는다
    return players;
}