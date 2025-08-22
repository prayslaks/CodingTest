#include<iostream>
#include<queue>

using namespace std;

//격자
int N, M;
int grid[1000][1000];
int dw[4]{ 0, 1, 0, -1 };
int dh[4]{ 1, 0, -1, 0 };
void print(int N, int M)
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//익지않았다면 0
//비어있다면 -1
//익어있다면 1
int tomatoExpandCount;
bool visited[100][100];
void dfs(pair<int, int> p)
{
	//방문
	visited[p.first][p.second] = true;

	for (int i = 0; i < 4; i++)
	{
		//상하좌우
		int y = dh[i] + p.first;
		int x = dw[i] + p.second;

		//유효
		if (x < 0 || x >= M || y < 0 || y >= N)
			continue;

		//방문 조건 확인
		if (grid[y][x] == -1 || visited[y][x])
			continue;

		//다음으로
		dfs(make_pair(y, x));
	}
}

int main()
{
	//입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//격자 크기 입력
	cin >> M >> N;

	//토마토 방문 예약
	queue<pair<int, int>> reserved;

	//안 익은 토마토
	int leftTomato = 0;

	//토마토 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
			{
				reserved.push(make_pair(i, j));
			}
			else if (grid[i][j] == 0)
			{
				leftTomato++;
			}
		}
	}

	//남은 토마토의 개수
	if (leftTomato == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	//시간
	int time = 0;

	//방문 예약이 남아있는 동안
	while (reserved.empty() == false)
	{
		//이미 다 익음
		if (leftTomato == 0)
			break;

		//시간 경과
		time++;

		//다음 방문
		queue<pair<int, int>> temp;

		while (reserved.empty() == false)
		{
			//이번 방문
			pair<int, int> pop = reserved.front();
			reserved.pop();

			for (int i = 0; i < 4; i++)
			{
				//상하좌우
				int y = dh[i] + pop.first;
				int x = dw[i] + pop.second;

				//유효
				if (x < 0 || x >= M || y < 0 || y >= N)
					continue;

				//방문 조건 확인
				if (grid[y][x] == -1 || grid[y][x] == 1)
					continue;

				//토마토가 익는다
				grid[y][x] = 1;
				leftTomato--;
				
				//다음 턴에 방문할 예정
				temp.push(make_pair(y, x));
			}
		}

		//복사
		reserved = temp;

		//현황
		//print(N, M);
	}

	if (leftTomato > 0)
	{
		//모든 토마토가 익지 못했다
		cout << -1 << endl;
	}
	else
	{
		//모든 토마토가 익는데 걸리는 시간
		cout << time << endl;
	}
}