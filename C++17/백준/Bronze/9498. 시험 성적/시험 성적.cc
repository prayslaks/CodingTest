#include<iostream>

using namespace std;

int main()
{
	int score;
	cin >> score;
	if (score < 60)
		cout << "F";
	else if (score < 70)
		cout << "D";
	else if (score < 80)
		cout << "C";
	else if (score < 90)
		cout << "B";
	else
		cout << "A";
}