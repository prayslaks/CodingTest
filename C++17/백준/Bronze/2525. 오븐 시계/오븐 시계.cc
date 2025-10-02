#include<iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	A = (A + ((B + C) / 60)) % 24;
	B = (B + C) % 60;
	cout << A << " " << B;
}