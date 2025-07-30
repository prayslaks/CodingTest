#include<string>
#include<iostream>

using namespace std;

string strSum(string a, string b)
{
    //길이 비교
    int lenA = a.length();
    int lenB = b.length();
    int min = lenA;
    int max = lenB;

    //승수
    int next = 0;

    //결과
    string result = "";

    //덧셈
    int s = 1;

    //더 긴 B까지 다 할때까지 
    for (s = 1; s <= lenB; s++)
    {
        if (s <= lenA)
        {
            //A-B-승수의 덧셈 가능
            int valueA = a[lenA - s] - '0';
            int valueB = b[lenB - s] - '0';
            int sum = (valueA + valueB + next);

            result += sum % 10 + '0';
            next = sum / 10;
        }
        else if(next >= 1)
        {
            //B-승수의 덧셈 가능
            int valueB = b[lenB - s] - '0';
            int sum = (valueB + next);

            result += sum % 10 + '0';
            next = sum / 10;
        }
        else
        {
            //B의 나머지
            result += b[lenB - s];
        }
    }

    //마지막 남은 승수
    if (next >= 1)
    {
        result += next + '0';
    }

    //반전
    string final = "";
    for (int i = result.length() - 1; i >= 0; i--)
    {
        final += result[i];
    }

    //결과
    return final;
}

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        string first = "0";
        string second = "1";
        string current;

        //문자열 덧셈 이용
        for (int i = 2; i <= n; i++)
        {
            current = strSum(first, second);
            first = second;
            second = current;
        }

        //출력
        cout << current << endl;
    }
}