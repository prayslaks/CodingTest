#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> result;
    result.push_back(0);
    result.push_back(1);
    result.push_back(2);

    for (int i = 3; i <= n; i++)
    {
        result.push_back((result[i - 1] + result[i - 2]) % 10007);
    }

    cout << result[n] << endl;
}