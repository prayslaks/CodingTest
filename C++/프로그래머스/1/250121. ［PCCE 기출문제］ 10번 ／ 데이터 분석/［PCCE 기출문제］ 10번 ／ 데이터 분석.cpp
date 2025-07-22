#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<vector<int>> temp;
    
    //추출 컬럼
    int idx = -1;
    if(ext == "code")
        idx = 0;
    else if(ext == "date")
        idx = 1;
    else if(ext == "maximum")
        idx = 2;
    else if(ext == "remain")
        idx = 3;
        
    //추출
    for(int i = 0; i < data.size(); i++)
        if(data[i][idx] < val_ext)
            temp.push_back(data[i]);
    
    //정렬 컬럼
    int sort = -1;
        if(sort_by == "code")
        sort = 0;
    else if(sort_by == "date")
        sort = 1;
    else if(sort_by == "maximum")
        sort = 2;
    else if(sort_by == "remain")
        sort = 3;
    
    //정렬
    for(int i = 0; i < temp.size() - 1; i++)
        for(int j = i + 1; j < temp.size(); j++)
            if(temp[i][sort] > temp[j][sort])
            {
                vector<int> ex = temp[i];
                temp[i] = temp[j];
                temp[j] = ex;
            }
    
    return temp;
}