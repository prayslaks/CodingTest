#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	cout << setprecision(10);
	cout << static_cast<double>(A) / static_cast<double>(B) << endl;
}