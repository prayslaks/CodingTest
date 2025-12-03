#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

// bfs
int bfs(int start, const vector<vector<int>>& connected)
{
    int counter = 0;
    unordered_map<int, bool> visited;
    queue<int> reserved;
    
    // 송전탑 예약
    reserved.push(start);
    visited[start] = true;
    counter++;
    
    while(reserved.empty() == false)
    {
        // 이번 예약
        const int current = reserved.front();
        reserved.pop();
        
        // 현재 노드와 연결된 이웃
        for(const int neighbor : connected[current])
        {
            // 이미 방문
            if(visited.find(neighbor) != visited.end())
            {
                continue;
            }
            
            // 노드 예약
            reserved.push(neighbor);
            visited[neighbor] = true;
            counter++;
        }
    }
    
    return counter;
}

// target 간선을 제외한 나머지가 연결되었다 가정
int testCut(const int target, vector<vector<int>> connected, vector<vector<int>> wires)
{
    // 탐색을 시작할 두 노드
    int startA = -1;
    int startB = -1;
    
    for(int i = 0; i < wires.size(); i++)
    {
        // 간선의 양 끝
        int a = wires[i][0] - 1;
        int b = wires[i][1] - 1;
        
        // 목표 간선이라면 건너뛰기
        if(i == target)
        {
            startA = a;
            startB = b;
            continue;
        }
        
        // 상호 연결 마킹
        connected[a].push_back(b);
        connected[b].push_back(a);
    }
    
    // A와 B의 크기를 구한다
    cout << "startA : " << startA << endl; 
    cout << "startB : " << startB << endl;
    cout << "now on bfs" << endl;
    const int resultA = bfs(startA, connected);
    const int resultB = bfs(startB, connected);
    
    cout << resultA << endl;
    cout << resultB << endl;
    
    //탐색 후 결과 반환
    return abs(resultA - resultB);
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 10000;
    
    // 각 노드 별로 어떤 노드와 간선이 있는 지 빠르게 찾기 위함
    vector<vector<int>> connected;
    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        connected.push_back(temp);
    }
    
    // 자르는 간선을 바꿔가면서 시도
    for(int i = 0; i < wires.size(); i++)
    {
        const int result = testCut(i, connected, wires);
        if(result < answer)
        {
            answer = result;
        }
    }
    
    return answer;
}