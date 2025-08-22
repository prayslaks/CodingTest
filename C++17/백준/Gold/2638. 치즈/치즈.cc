#include<iostream>
#include<vector>

using namespace std;

//격자
int N, M;
int grid[100][100];
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

//치즈 외부는 2
//치즈 자체는 1
//치즈 내부는 0
bool visited[100][100];
void dfs(pair<int, int> p)
{
	//방문
	visited[p.first][p.second] = true;
	grid[p.first][p.second] = 2;

	for (int i = 0; i < 4; i++)
	{
		//상하좌우
		int y = dh[i] + p.first;
		int x = dw[i] + p.second;

		//유효
		if (x < 0 || x >= M || y < 0 || y >= N)
			continue;

		//치즈가 있거나 이미 방문했다면
		if (grid[y][x] == 1 || visited[y][x])
			continue;

		//다음으로
		dfs(make_pair(y, x));
	}
}
void update()
{
	dfs(make_pair(0, 0));
	for (int i = 0; i < 10000; i++)
		visited[i / 100][i % 100] = false;
}

int main()
{
	//입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//격자 크기 입력
	cin >> N >> M;

	//치즈 개수
	int cheese = 0;

	//치즈 위치 저장
	vector<pair<int, int>> pos;

	//치즈 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
			{
				pos.push_back(make_pair(i, j));
				cheese++;
			}
		}
	}

	//시간
	int time = 0;
	
	//치즈가 남아있는 동안
	while (cheese > 0)
	{
		//시간 경과
		time++;

		//업데이트
		update();

		//녹는 치즈
		vector<pair<int, int>> target;

		for (pair<int, int> p : pos)
		{
			//유효
			if (grid[p.first][p.second] != 1)
				continue;

			//노출면
			int face = 0;

			for (int i = 0; i < 4; i++)
			{
				//상하좌우
				int y = dh[i] + p.first;
				int x = dw[i] + p.second;

				//유효
				if (x < 0 || x >= M || y < 0 || y >= N)
					continue;

				//노출 증가
				if (grid[y][x] == 2)
					face++;
			}

			//녹게 되는 치즈
			if (face >= 2)
				target.push_back(make_pair(p.first, p.second));
		}

		//녹는 치즈 처리
		for (pair<int, int> t : target)
		{
			grid[t.first][t.second] = 2;
			cheese--;
		}
		target.clear();
	}

	cout << time << endl;
}