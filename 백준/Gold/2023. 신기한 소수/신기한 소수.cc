#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//목표 길이
int length;

//결과
vector<int> result;

//소수 확인
bool checkPrime(int value)
{
    if (value <= 1)
        return false;

    if (value % 2 == 0)
        return value == 2 ? true : false;

    for (int i = 3; i <= sqrt(value); i+=2)
        if (value % i == 0)
            return false;

    return true;
}

//뒤편에 추가해도 소수의 가능성이 있는 홀수들
int nextOdd[5] = { 1, 3, 7, 9 };

//하나씩 늘려가며 확인
void dfs(int construct, int len)
{
    for (int i = 0; i < 5; i++)
    {
        int newConstrut = construct * 10 + nextOdd[i];
        int newLen = len + 1;

        if (checkPrime(newConstrut))
        {
            if (newLen == length)
            {
                result.push_back(newConstrut);
            }
            else
            {
                dfs(newConstrut, newLen);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> length;

    //소수 외에는 시작도 불가
    int firstPrime[4] = { 2, 3, 5, 7 };

    //예외 처리
    if (length == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << firstPrime[i] << '\n';
        }
    }
    else
    {
        //탐색
        for (int i = 0; i < 4; i++)
        {
            dfs(firstPrime[i], 1);
        }

        //정렬
        sort(result.begin(), result.end());

        //결과
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << '\n';
        }
    }
}