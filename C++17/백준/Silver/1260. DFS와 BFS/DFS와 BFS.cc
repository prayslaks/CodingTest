#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void executeBFS(vector<vector<int>>& ref, int start);
void BFS(vector<vector<int>>& ref, int pos, int size, vector<bool>& visited, queue<int>& next);
void executeDFS(vector<vector<int>>& ref, int start);
void DFS(vector<vector<int>>& ref, int pos, int size, vector<bool>& visited);

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	//구축
	vector<vector<int>> vertices;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(0);
		}
		vertices.push_back(temp);
	}

	//간선
	for (int i = 0; i < M; i++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		vertices[p1 - 1][p2 - 1] = 1;
		vertices[p2 - 1][p1 - 1] = 1;
	}

	//DFS
	executeDFS(vertices, V - 1);

	//줄바꿈
	cout << endl;

	//BFS
	executeBFS(vertices, V - 1);
}

void executeDFS(vector<vector<int>>& ref, int start)
{
	//정점 개수
	int size = ref.size();

	//방문 배열
	vector<bool> visited;
	for (int i = 0; i < size; i++)
	{
		visited.push_back(false);
	}

	//DFS 시작
	DFS(ref, start, size, visited);
}

void DFS(vector<vector<int>>& ref, int pos, int size, vector<bool>& visited)
{
	//방문
	visited[pos] = true;
	cout << pos + 1 << " ";

	//다음 후보 탐색
	for (int i = 0; i < size; i++)
	{
		//자기 자신
		if (i == pos)
			continue;

		//방문 가능
		if (ref[pos][i] == 1 && visited[i] == false)
		{
			//방문
			DFS(ref, i, size, visited);
		}
	}
}

void executeBFS(vector<vector<int>>& ref, int start)
{
	//정점 개수
	int size = ref.size();

	//방문 배열
	vector<bool> visited;
	for (int i = 0; i < size; i++)
	{
		visited.push_back(false);
	}

	//BFS 큐
	queue<int> next;

	//첫번째 정점
	visited[start] = true;
	cout << start + 1 << " ";

	//BFS 시작
	BFS(ref, start, size, visited, next);
}

void BFS(vector<vector<int>>& ref, int pos, int size, vector<bool>& visited, queue<int>& next)
{
	//다음 후보 탐색
	for (int i = 0; i < size; i++)
	{
		//자기 자신
		if (i == pos)
			continue;

		//방문 가능
		if (ref[pos][i] == 1 && visited[i] == false)
		{
			//방문
			visited[i] = true;
			cout << i + 1 << " ";

			//예약
			next.push(i);
		}
	}

	if (next.empty())
		return;

	//다음 정점
	int go = next.front();
	next.pop();

	//방문
	BFS(ref, go, size, visited, next);
}