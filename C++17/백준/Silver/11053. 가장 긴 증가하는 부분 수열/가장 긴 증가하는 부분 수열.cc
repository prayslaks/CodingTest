#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	//최대 길이
	int globalMax = 1;

	//모든 부분 수열은 크기가 1인 증가하는 수열
	vector<int> length(N, 1);

	for (int i = 1; i < A.size(); i++)
	{
		//나보다 작은 이전 요소 중 최대 길이를 탐색
		int localMax = -1;
		for (int j = i - 1; j >= 0; j--)
			if (A[j] < A[i] && length[j] > localMax)
				localMax = length[j];

		//찾았다면 이번 요소의 최대 길이 업데이트
		if (localMax != -1)
			length[i] = localMax + 1;

		//전체 수열 중 최대 길이 업데이트
		if (globalMax < length[i])
			globalMax = length[i];
	}

	//출력
	cout << globalMax;
}