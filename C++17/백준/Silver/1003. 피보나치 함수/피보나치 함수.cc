#include<iostream>

using namespace std;

int main()
{
	//테스트 수
	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		//N번째 피보나치
		int N;
		cin >> N;

		int first[2]{ 1, 0 };
		int second[2]{ 0, 1 };

		if (N == 0)
		{
			cout << first[0] << " " << first[1] << endl;
			continue;
		}

		if (N == 1)
		{
			cout << second[0] << " " << second[1] << endl;
			continue;
		}

		//중간 결과
		int current[2]{ -1, -1 };
		for (int i = 2; i <= N; i++)
		{
			//업데이트하면서 목표 수까지 이동
			current[0] = first[0] + second[0];
			current[1] = first[1] + second[1];
			first[0] = second[0];
			first[1] = second[1];
			second[0] = current[0];
			second[1] = current[1];
		}

		cout << current[0] << " " << current[1] << endl;
	}
}