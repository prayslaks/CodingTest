#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Point
{
    int y;
    int x;
    int move;
    Point() : y(-1), x(-1), move(-1) {}
    Point(int inY, int inX, int inMove) : y(inY), x(inX), move(inMove) {}
    bool operator==(Point& other) { return this->y == other.y && this->x == other.x; }
};

//미로의 높이와 너비
int height;
int width;

//시작, 종료, 레버
Point startPos = Point();
Point endPos = Point();
Point leverPos = Point();

//주요 지점을 검색
void findMarks(vector<string> copy)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(copy[i][j] == 'S')
            {
                startPos = Point(i, j, 0);
            }
            else if(copy[i][j] == 'E')
            {
                endPos = Point(i, j, 0);
            }
            else if(copy[i][j] == 'L')
            {
                leverPos = Point(i, j, 0);
            }
        }
    }
}

//이동
int dw[4] = { 0, 1, 0, -1 };
int dh[4] = { 1, 0, -1, 0 };

//bfs로 지정한 시작지점에서 목표지점까지 탐색
Point move(vector<string> copy, Point pointA, Point pointB)
{    
    //방문 행렬 구축
    vector<vector<bool>> visited;
    for(int i = 0; i < height; i++)
    {
        vector<bool> temp(width, false);
        visited.push_back(temp);
    }
    
    //예약
    queue<Point> reserved;
    
    //시작 좌표
    reserved.push(pointA);
    
    //더 이상 이동 불가능할 때까지
    while(reserved.empty() == false)
    {
        //이번 이동 위치
        Point cur = reserved.front();
        reserved.pop();
        
        //목표에 도달
        if(cur == pointB)
        {
            return cur;
        }
        
        //상하좌우
        for(int i = 0; i < 4; i++)
        {
            //상화좌우 좌표
            int y = cur.y + dh[i];
            int x = cur.x + dw[i];
            
            //유효 좌표 검증
            bool check1 = y < 0 || y >= height;
            bool check2 = x < 0 || x >= width;
            if(check1 || check2)
            {
                continue;
            }
            
            //지나갈 수 없는 벽
            if(copy[y][x] == 'X')
            {
                continue;
            }
            
            //이미 방문한 좌표
            if(visited[y][x])
            {
                continue;
            }
            
            //예약
            visited[y][x] = true;
            reserved.push(Point(y, x, cur.move + 1));
        }
    }
    
    //도달 불가
    return Point();
}

int solution(vector<string> maps) 
{
    //높이와 너비
    height = maps.size();
    width = maps[0].length();
    
    //주요 지점 마킹
    findMarks(maps);
    
    //디버깅
    cout << startPos.y << startPos.x << endl;
    cout << leverPos.y << leverPos.x << endl;
    cout << endPos.y << endPos.x << endl;
    
    //미로 이동
    Point result1 = move(maps, startPos, leverPos);
    
    //도달 불가
    if(result1.move == -1)
    {
        return -1;
    }
        
    //미로 이동
    Point result2 = move(maps, leverPos, endPos);
    
    //도달 불가
    if(result2.move == -1)
    {
        return -1;
    }

    //결과
    return result1.move + result2.move;
}