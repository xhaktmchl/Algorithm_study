#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2178 c++ VOV] 미로 탐색 
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
int gr[MAX][MAX];
bool visit[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int r, int c) {
	queue<pair<int,int>> q;
	q.push({ r,c }); visit[r][c] = 1; // 방문처리
	dist[r][c] = 1; // 거리 저장

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		// 4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nr = r + dy[i];
			int nc = c + dx[i];

			if (nr<1 || nr >n || nc<1 || nc>m) { continue; } // 범위검사
			if (!visit[nr][nc] && gr[nr][nc] == 1) { // 방문, 이동유무 검사
				q.push({ nr,nc }); visit[nr][nc] = 1; // 큐 푸쉬 방문처리
				dist[nr][nc] = dist[r][c] + 1; // 거리저장
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	//cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 2차원 그래프 입력
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &gr[i][j]);
		}
	}
	
	bfs(1, 1);

	printf("%d\n", dist[n][m]);
	return 0;
}
