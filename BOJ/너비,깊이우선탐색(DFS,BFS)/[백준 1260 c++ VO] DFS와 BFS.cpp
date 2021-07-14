#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<queue>
using namespace std; // cin,cout 편하게 사용 라이브러리 

// [백준 1260 c++ VO] DFS와 BFS
// 문제: 기본 인접행렬 그래프 dfs,bfs 탐색 
// 접근1: 기본 인접행렬 그래프 탐색
// 풀이: 
// 인접행렬 완성
// dfs 탐색
// bfs탐색

int visited[10001];
int adj_arr[1001][1001];
int n, m, v;

// dfs
void dfs(int v) {
	// 방문처리
	visited[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		// 간선존재, 방문하지 않았으면 
		if (visited[i] == 0 && adj_arr[v][i] == 1) {
			dfs(i);
		}
	}
}

// bfs
queue<int> q;
int visited1[10001];
void bfs(int v) {

	q.push(v);
	visited1[v] = 1;

	while (!q.empty()) {
		// 큐에서 꺼내면서 방문처리
		v = q.front();
		cout << v << " ";
		q.pop();

		for (int i = 1; i <= n; i++) {
			// 간선존재, 방문하지 않았으면 
			if (visited1[i] == 0 && adj_arr[v][i] == 1) {
				q.push(i);
				visited1[i] = 1;
			}

		}

	}

}
int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int row, col;
		cin >> row >> col;
		adj_arr[row][col] = 1;
		adj_arr[col][row] = 1;
	}

	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}
