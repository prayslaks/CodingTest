#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//에라토스테네스의 체
vector<bool> isPrime()
{
    //전부 소수로 간주하고 초기화
    vector<bool> primes(2999, true);
    
    //0과 1은 소수가 아님
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= 2998; i++)
    {
        //소수를 발견했다면
        if (primes[i])
        {
            //해당 소수의 배수를 찾아 마킹
            for (int j = i * i; j <= 2998; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    //범위 내의 소수를 다 구한다
    //최대 1000+999+998 = 2997
    vector<bool> primes = isPrime();

    //서로 다른 숫자 3개
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                //체를 통해 확인
                if (primes[sum])
                    answer++;
            }
        }
    }

    cout << answer << endl;
    return answer;
}