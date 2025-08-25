#include<iostream>
#include<queue>

using namespace std;

int N, K;
bool visited[100001];

//위치 - 시간 쌍
queue<pair<int, int>> reserved;

int main()
{
	//둘의 위치를 입력 받는다
	cin >> N >> K;

	//첫번째 탐색 위치인 수빈의 시작 위치 푸시
	reserved.push(make_pair(N, 0));

	//수빈의 시작 위치부터 너비 우선 탐색 시작
	while (reserved.empty() == false)
	{
		//다음 탐색 위치 팝
		pair<int, int> current = reserved.front();
		reserved.pop();

		if (current.first == K)
		{
			cout << current.second << endl;
			return 0;
		}

		//이미 탐색한 위치
		if (visited[current.first])
			continue;

		//수빈의 위치 방문 마킹
		visited[current.first] = true;

		//다음 방문 위치
		int next[3]{ current.first - 1, current.first + 1, 2 * current.first };
		for (int i = 0; i < 3; i++)
		{
			//범위를 넘어가는 접근
			if (next[i] < 0 || next[i] > 100000)
				continue;

			//다음으로
			reserved.push(make_pair(next[i], current.second + 1));
		}
	}
}