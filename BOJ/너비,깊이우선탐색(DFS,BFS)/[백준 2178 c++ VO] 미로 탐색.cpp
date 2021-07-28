#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 2178 c++ VO] 미로 탐색 
// 문제: 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수
// 접근: 이차원 그래프 최단거리 -> bfs
// 이동거리를 저장하는 dist배열 따로 저장
// 시간복잡도: 
// 풀이 :
// 그래프 입력
// bfs 시작
// 탐색하며 dist에 이동거리 저장
// 주의: 
//: ios::sync_with_stdio(false); 사용시 cin,scanf 같이 쓰면 오류
#define MAX 101
int n, m;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dist[MAX][MAX]; // 해당 노드까지 이동거리 배열

void bfs(int row, int col) {

	queue<pair<int, int>> q;
	//방문처리
	q.push({ row,col }); visited[row][col] = 1;
	dist[row][col] = 1; // 이동거리 젖장

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int currow = row+ dy[i];
			int curcol = col + dx[i];
			
			//범위검사
			if (currow<1 || currow>n || curcol<1 || curcol>m) { continue; }
			if (visited[currow][curcol] == 0 && graph[currow][curcol] == 1) { // 방문않했는데 이동가능하면
				q.push({ currow,curcol }); visited[currow][curcol] = 1;
				dist[currow][curcol] = dist[row][col] + 1; // 그 전에서 이동 거리는 1 증가
			}
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	bfs(1, 1); // 1,1에서 bfs
	printf("%d\n", dist[n][m]);
	return 0;
}
