#include<iostream>
#include<string>

using namespace std;

int main()
{
	while (true)
	{
		string input;
		getline(cin, input);
		if (input == "")
			break;

		cout << (input[0] - '0') + (input[2] - '0') << endl;
	}
}