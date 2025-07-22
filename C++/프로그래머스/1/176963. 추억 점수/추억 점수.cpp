#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    //그리움 점수를 빠르게 검색하기 위한 맵
    unordered_map<string, int> umap;
    for(int i = 0; i < yearning.size(); i++)
    {
        umap[name[i]] = yearning[i];
    }
    
    //사진 별로 추억 점수 매기기
    for(int i = 0; i < photo.size(); i++)
    {
        //이번 사진의 추억 점수
        int score = 0;
        
        //연산
        for(string p : photo[i])
        {
            //해당 인물의 추억 점수 존재함
            if(umap.find(p) != umap.end())
            {
                //누적
                score += umap[p];
            }
        }
        
        //사진 별로 저장
        answer.push_back(score);
    }
    
    return answer;
}