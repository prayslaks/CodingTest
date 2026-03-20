#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <queue>

using namespace std;

struct songData
{
    int idx;
    int play;
    
    songData() { }
    
    songData(int idx, int play)
    {
        this->idx = idx;
        this->play = play;
    }
};

int compareSong(songData a, songData b)
{
    return a.play > b.play;
}

struct genreContainer
{
    int play;
    vector<songData> songDatas;
    
    genreContainer() { }
    
    genreContainer(int idx, int play)
    {
        this->play = play;
        this->songDatas.push_back(songData(idx, play));
    }
    
    void add(int idx, int play)
    {
        this->play += play;
        this->songDatas.push_back(songData(idx, play));
    }
};

int compareContainer(genreContainer a, genreContainer b)
{
    return a.play > b.play;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    
    // 장르 별 재생 횟수를 종합한다
    unordered_map<string, genreContainer> genreContainerMap;
    for(int i = 0; i < genres.size(); i++)
    {
        string genre = genres[i];
        if(genreContainerMap.find(genre) == genreContainerMap.end())
        {
            genreContainerMap[genre] = genreContainer(i, plays[i]);
        }
        else
        {
            genreContainerMap[genre].add(i, plays[i]);
        }
    }
    
    // 벡터로 옮겨 담는다
    vector<genreContainer> genreContainers;
    for (auto it = genreContainerMap.begin(); it != genreContainerMap.end(); ++it)
    {        
        // 벡터에 넣는다
        genreContainers.push_back(it->second);
    }
    
    // 정렬한다
    sort(genreContainers.begin(), genreContainers.end(), compareContainer);
    
    // 수록한다
    for (auto it = genreContainers.begin(); it != genreContainers.end(); ++it)
    {
        // 잠시 정렬해준다
        sort(it->songDatas.begin(), it->songDatas.end(), compareSong);
        if(it->songDatas.size() >= 2)
        {
            answer.push_back(it->songDatas[0].idx);
            answer.push_back(it->songDatas[1].idx);   
        }
        else
        {
            answer.push_back(it->songDatas[0].idx);
        }
    }
    
    return answer;
}