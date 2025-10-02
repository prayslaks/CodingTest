#include<iostream>

using namespace std;

int main()
{
	srand(NULL);
	int dice[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> dice[i];
	}

	if (dice[0] == dice[1] && dice[1] == dice[2])
	{
		cout << 10000 + dice[0] * 1000;
	}
	else if (dice[0] == dice[1])
	{
		cout << 1000 + dice[0] * 100;
	}
	else if (dice[1] == dice[2])
	{
		cout << 1000 + dice[1] * 100;
	}
	else if (dice[0] == dice[2])
	{
		cout << 1000 + dice[0] * 100;
	}
	else
	{
		int result = max(dice[0], dice[1]);
		result = max(result, dice[2]);
		cout << result * 100;
	}
}