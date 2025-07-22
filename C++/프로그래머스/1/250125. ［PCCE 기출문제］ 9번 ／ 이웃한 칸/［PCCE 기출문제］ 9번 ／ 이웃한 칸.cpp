#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {

    //경계
    int n = board.size();
    
    //카운트
    int count = 0;
    
    //상하좌우
    vector<int> dh {0, 1, -1, 0};
    vector<int> dw {1, 0, 0, -1};
    
    //해당 좌표의 상하좌우 확인
    for(int i = 0; i < 4; i++)
    {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        if(h_check >= 0 && h_check < n && w_check >= 0 && w_check < n)
            if(board[h][w] == board[h_check][w_check])
                count++;
    }
    
    return count;
}