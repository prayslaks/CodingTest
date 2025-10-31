#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{   
    int biggerMax = 0;
    int smallerMax = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = temp;
        }
        
        if(sizes[i][0] > biggerMax)
        {
            biggerMax = sizes[i][0];
        }
        
        if(sizes[i][1] > smallerMax)
        {
            smallerMax = sizes[i][1];
        }
    }
    
    return biggerMax * smallerMax;
}