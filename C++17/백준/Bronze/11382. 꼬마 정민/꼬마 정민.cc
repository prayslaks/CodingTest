#include<iostream>

using namespace std;

int main()
{
	long sum = 0;
	long input;
	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		sum += input;
	}
	cout << sum << endl;
}