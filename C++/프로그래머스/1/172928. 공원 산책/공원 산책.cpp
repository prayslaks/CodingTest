#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    
    //직사각형 격자 공원의 정보
    int height = park.size();
    int width = park[0].length();
    
    //강아지 출발 위치 검색
    int pos_x = 0;
    int pos_y = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(park[i][j] == 'S')
            {
                pos_y = i;
                pos_x = j;
            }
        }
    }
    
    //명령 수행
    for (auto s : routes)
    {
        //방향
        string op = s.substr(0, 1);
        int move = stoi(s.substr(2, 1));
        
        //이동 벡터
        int move_x = 0;
        int move_y = 0;
        if (op.compare("N") == 0)
            move_y = -move;
        else if (op.compare("S") == 0)
            move_y = move;
        else if (op.compare("W") == 0)
            move_x = -move;
        else if (op.compare("E") == 0)
            move_x = move;

        //범위 확인
        bool limit_x = pos_x + move_x < 0 || pos_x + move_x >= width;
        bool limit_y = pos_y + move_y < 0 || pos_y + move_y >= height;
        if (limit_x || limit_y)
            continue;

        //장애물 확인
        bool skip = false;
        if (move_y < 0)
            for (int i = -1; i >= move_y; i--)
                if (park[pos_y + i][pos_x] == 'X')
                    skip = true;
        if (move_y > 0)
            for (int i = 1; i <= move_y; i++)
                if (park[pos_y + i][pos_x] == 'X')
                    skip = true;
        if (move_x < 0)
            for (int i = -1; i >= move_x; i--)
                if (park[pos_y][pos_x + i] == 'X')
                    skip = true;
        if (move_x > 0)
            for (int i = 1; i <= move_x; i++)
                if (park[pos_y][pos_x + i] == 'X')
                    skip = true;
        if (skip)
            continue;

        //이동
        pos_x += move_x;
        pos_y += move_y;
    }

    //결과
    vector<int> answer;
    answer.push_back(pos_y);
    answer.push_back(pos_x);
    return answer;
}