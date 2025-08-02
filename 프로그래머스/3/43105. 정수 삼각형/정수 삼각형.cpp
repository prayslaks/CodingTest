#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{    
    //맨 밑줄부터 최상위 1인까지
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        //이번 행의 모든 요소에 대해
        for (int j = 0; j < triangle[i].size(); j++)
        {
            //하위 요소 중 더 큰 값을 자신에 더한다
            if (triangle[i + 1][j] < triangle[i + 1][j + 1])
            {
                triangle[i][j] += triangle[i + 1][j + 1];
            }
            else
            {
                triangle[i][j] += triangle[i + 1][j];
            }
        }
    }

    return triangle[0][0];
}