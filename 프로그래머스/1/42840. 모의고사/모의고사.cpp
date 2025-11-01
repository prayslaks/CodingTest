#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    
    vector<int> counter;
    counter.push_back(0);
    counter.push_back(0);
    counter.push_back(0);
    
    vector<vector<int>> num;
    vector<int> num1 { 1, 2, 3, 4, 5 };
    vector<int> num2 { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> num3 { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    num.push_back(num1);
    num.push_back(num2);
    num.push_back(num3);
    
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(answers[i] == num[j][i % num[j].size()])
            {
                counter[j]++;
            }    
        }
    }
    
    cout << counter[0] << " " << counter[1] << " " << counter[2] << endl;
    
    //번호-순위
    vector<pair<int, int>> res;
    res.push_back(make_pair(1, counter[0]));
    res.push_back(make_pair(2, counter[1]));
    res.push_back(make_pair(3, counter[2]));
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            if(res[i].second < res[j].second)
            {
                pair<int, int> temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    
    int most = -1;
    for(int i = 0; i < 3; i++)
    {
        if(res[i].second >= most)
        {
            answer.push_back(res[i].first);
            most = res[i].second;
        }
    }
    
    return answer;
}