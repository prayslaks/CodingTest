#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> nums)
{
    //맵
    unordered_map<int, int> umap;
    
    //종류에 따라 총 몇 개인지 맵 구축 
    for(auto n : nums)
        if(umap.find(n) == umap.end())
            umap[n] = 1;
        else
            umap[n]++;
    
    //모두 다른 종류여도 어차피 (nums.size() / 2)개 밖에 못 뽑음
    int a = nums.size() / 2;
    
    //모두 같은 종류라면 (nums.size() / 2)개를 뽑아도 1개 밖에 안됨
    int b = umap.size();
    
    //둘 중에 최솟값
    return min(a, b);
}