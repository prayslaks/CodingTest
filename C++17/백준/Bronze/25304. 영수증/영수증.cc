#include<iostream>

using namespace std;

int main()
{
	int total = 0;
	int X, N;
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		total += a * b;
	}

	cout << ((total == X) ? "Yes" : "No");
}