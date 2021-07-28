#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 7562 c++ VO] 나이트의 이동
// 문제: 나이트가 한 지점으로부터 목표지점까지 이동하는데 최소이동횟수 구하기
// 접근: 이차원 그래프 최소이동횟수 -> bfs -> dist배열에 이동거리 저장하며 탐색
// 시간복잡도: ??
// 풀이: 
// 시작, 목표 행렬 값 입력
// 기본 bfs 하는데 이동시 이동 횟수를 저장하면서
// 8방향 탐색
// 원하는 지점의 dist배열 출력
// 개념: memset(visited, 채우는 값, sizeof(visited)); 배열을 초기화 시킴 , 헤더:#include <cstring> // memset 헤더

#define MAX 301
int t, n;
int visited[MAX][MAX];
int dist[MAX][MAX];
int endrow, endcol;
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };

void bfs(int row, int col) {
	queue<pair<int, int>> q;
	// 큐에 푸쉬, 방문처리 , 거리저장
	q.push({ row,col }); visited[row][col] = 1;
	dist[row][col] = 0;

	while (!q.empty()) {
		// 현재위치
		int row = q.front().first; 
		int col = q.front().second;
		q.pop();
		// 8방향 탐색
		for (int i = 0; i < 8; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];

			// 범위검사
			if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) {continue;}
			if (visited[nrow][ncol] == 0) { // 방문 검사
				// 큐에 푸쉬, 방문처리, 거리저장
				q.push({ nrow,ncol }); visited[nrow][ncol] = 1;
				dist[nrow][ncol] = dist[row][col] + 1;
			}

		}
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		int row, col;
		cin >> row >> col;
		cin >> endrow >> endcol;

		bfs(row, col);
		
		cout << dist[endrow][endcol] << '\n';
	}
	return 0;
}
