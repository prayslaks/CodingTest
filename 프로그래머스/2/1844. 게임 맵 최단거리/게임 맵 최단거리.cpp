#include<vector>
#include<queue>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct Pos
{
    int Y;
    int X;
    int Move;
    
    Pos(int inY, int inX, int inMove = 0) : 
        Y(inY), 
        X(inX),
        Move(inMove) {}  
};

//그리드 탐색 편의성
int dw[4] = { 0, 1, 0, -1 };
int dh[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> maps)
{
    //방문 여부 저장
    vector<vector<bool>> visited;
    for(int i = 0; i < maps.size(); i++)
    {
        vector<bool> temp(maps[i].size(), false);
        visited.push_back(temp);
    }
    
    //목표 좌표
    Pos destination = Pos(maps.size() - 1, maps[0].size() - 1);
    
    //A* 방식을 위한 우선순위 큐
    queue<Pos> reserved;
    
    //시작 좌표를 삽입
    reserved.push(Pos(0, 0, 1));
    
    //시작 좌표에 마킹
    visited[0][0] = true;
    
    //큐가 완전히 비어버릴 때까지
    while(reserved.empty() == false)
    {
        //이번 예약 좌표와 이동 거리
        Pos current = reserved.front();
        reserved.pop();
        
        //목표 위치 도달 확인
        bool check1 = current.Y == destination.Y;
        bool check2 = current.X == destination.X; 
        if(check1 && check2)
        {
            //이동 거리 반환
            return current.Move;
        }

        //동서남북을 확인한다
        for(int i = 0; i < 4; i++)
        {
            //방향
            int y = current.Y + dh[i];
            int x = current.X + dw[i];

            //유효하지 않은 접근
            if(y < 0 || y > destination.Y || x < 0 || x > destination.X)
            {
                continue;
            }

            //벽으로 가로막혀 있음
            if(maps[y][x] == false)
            {
                continue;
            }

            //아직 방문하지 않은 곳 확인
            if(visited[y][x] == false)
            {
                //방문 예정 좌표에 마킹
                visited[y][x] = true;

                //예약 추가
                reserved.push(Pos(y, x, current.Move + 1));
            }
        }
    }
    
    //해답 없음
    return -1;
}