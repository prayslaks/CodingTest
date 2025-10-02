#include<iostream>

using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	if (M - 45 < 0)
	{
		M = 60 + M - 45;
		H = (H - 1) < 0 ? 23 : H - 1;
	}
	else
	{
		M = M - 45;
	}
	cout << H << " " << M;
}