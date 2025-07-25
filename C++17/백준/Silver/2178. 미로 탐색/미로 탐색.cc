#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

//미로
int maze[1000][1000];

//미로 크기
int height;
int width;

//시작 위치와 종료 위치
int start[2];
int target[2];

//방문 표시
bool visited[1000][1000];

//부모
pair<int, int> parent[1000][1000];

//상하좌우
int dh[4]{ 1, 0, -1, 0 };
int dw[4]{ 0, 1, 0, -1 };

//미로 탐색
bool BFSMaze();

int main()
{
	int N, M;
	cin >> N >> M;
	cin.ignore();

	//미로 구축
	for (int i = 0; i < N; i++)
	{
		string input;
		getline(cin, input);
		for (int j = 0; j < input.length(); j++)
		{
			maze[i][j] = input[j] - '0';
		}
	}

	//미로 크기
	height = N;
	width = M;

	//방문 구축
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = false;
		}
	}

	//위치 초기화
	start[0] = 0;
	start[1] = 0;
	target[0] = N - 1;
	target[1] = M - 1;

	//BFS 미로 길찾기 실행
	if (BFSMaze() == false)
		return -1;

	//시작과 끝을 포함하여 카운트
	int count = 1;

	//종료 위치의 부모
	pair<int, int> p = make_pair(target[0], target[1]);
	
	//시작점으로 돌아올 때까지
	while (p.first != 0 || p.second != 0)
	{
		//카운트
		count++;

		//부모 업데이트
		p = parent[p.first][p.second];
	}

	//카운트 출력
	cout << count << endl;
}

bool BFSMaze()
{
	//예약
	queue<pair<int, int>> reserved;
	reserved.push({ start[0], start[1] });
	visited[start[0]][start[1]] = true;

	while (!reserved.empty())
	{
		//꺼낸다
		pair<int, int> t = reserved.front();
		int h = t.first;
		int w = t.second;
		reserved.pop();

		if (h == target[0] && w == target[1])
		{
			//성공
			return true;
		}
		else
		{
			//다음 후보 탐색
			for (int i = 0; i < 4; i++)
			{
				//이번에 탐색할 좌표
				int sh = h + dh[i];
				int sw = w + dw[i];

				//범위 바깥
				if (sh < 0 || height <= sh || sw < 0 || width <= sw)
					continue;

				//방문 가능
				if (maze[sh][sw] == 1 && visited[sh][sw] == false)
				{
					//방문
					visited[sh][sw] = true;

					//예약
					reserved.push(make_pair(sh, sw));

					//부모
					parent[sh][sw] = make_pair(h, w);
				}
			}
		}
	}

	//실패
	return false;
}