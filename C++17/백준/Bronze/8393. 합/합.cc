#include<iostream>

using namespace std;

int main()
{
	int sum = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}
	cout << sum;
}