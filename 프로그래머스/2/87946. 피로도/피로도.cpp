#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 던전 크기
int dungeonSize;

// 순열 경우의 수
vector<vector<int>> perm;

// output, visited, depth은 순열 구축 용으로 값 복사
void permutation(vector<int> output, vector<bool> visited, int depth)
{
    if(depth == dungeonSize)
    {   
        // 얻은 순열 경우의 수를 저장
        perm.push_back(output);
        return;
    }
    
    // 던전 크기만큼 순회하면서
    for(int i = 0; i < dungeonSize; i++)
    {        
        // 아직 방문하지 않은 원소
        if(visited[i] == false)
        {
            visited[i] = true;
            output[depth] = i;
            permutation(output, visited, depth + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    // 크기
    dungeonSize = dungeons.size();
    
    // 순열 경우의 수
    vector<int> output(dungeonSize, -1);
    
    // 방문 배열
    vector<bool> visited(dungeonSize, false);
    
    // 순열 탐색
    permutation(output, visited, 0);
    
    // 최댓값
    int max = -1;
    
    // cout << "permSize : " << perm.size() << endl;
    
    for(int t = 0; t < perm.size(); t++)
    {
        // 임시 피로도
        int temp = k;
        
        // 탐험 횟수
        int search = 0;

        // 순열대로 탐험 개시
        for(int i = 0; i < perm[t].size(); i++)
        {            
            int target = perm[t][i];
            
            if(dungeons[target][0] <= temp)
            {
                // 탐험 가능
                temp -= dungeons[target][1];
                search++;
            }
            
            // cout << target << " ";
        }
        
        // cout << "result : " << search << endl;
        
        // 최댓값 업데이트
        if(max < search)
        {
            max = search;
        }
    }
        
    // 최댓값 출력
    return max;
}