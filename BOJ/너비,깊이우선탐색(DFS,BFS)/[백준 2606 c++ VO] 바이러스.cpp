#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<queue>
using namespace std; // cin,cout 편하게 사용 라이브러리 

// [백준 2606 c++ VO] 바이러스
// 문제: 1번 컴퓨터를 통해 감염되는 컴퓨터의 갯수 구하기
// 점근1: : 기본 인접행렬 dfs : 연결된 노드탐색 
// 풀이: 
// 인접행렬 만들기
// 1부터 시작해서 dfs 탐색하며 감염 컴퓨터의 수 구하기

#define MAX 101
int n, edge;
int graph[MAX][MAX];
int visited[MAX];
int cnt = -1;
// 깊이우선
void dfs(int v) {
	// 방문처리
	visited[v] = 1;
	cnt++;
	// 인접노드 탐색
	for (int i = 1; i <= n; i++) {
		// 간선존재, 방문 안했으면
		if (visited[i] == 0 && graph[v][i] == 1) {
			dfs(i);
		}
	}
}

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n >> edge;
	// 인접행렬 완성
	for (int i = 0; i < edge; i++) {
		int row, col;
		cin >> row >> col;
		graph[row][col] = 1;
		graph[col][row] = 1;
	}
	// dfs 탐색
	dfs(1);
	cout << cnt;
	return 0;
}
