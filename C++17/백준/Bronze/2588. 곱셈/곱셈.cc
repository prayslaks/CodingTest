#include<iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	for (int i = B; i > 0; i /= 10)
	{
		cout << A * (i % 10) << endl;
	}
	cout << A * B << endl;
}