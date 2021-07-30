#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1261 c++ O] 알고스팟 
// 문제: (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하
// 접근: 이차원 그래프-> 최소회수 -> bfs-> 
// 벽을 안부숨(0)/ 벽 부숨(+1) 가중치 2개 -> 데크 / 큐2개 이용 -> 큐2개 이용 선택
// 현재 큐, 다음큐 두개를 생성해 같은 횟수로 벽을 부순 수 현재큐에 계속 넣어주고, 벽을 1 개 부숴야 하는 것은 다음 큐로 넣음
// 시간복잡도: O() 
// 풀이: 
// bfs
// 현재 큐, 다음 큐 생성
// 큐에푸쉬 방문처리
// 4방면 탐색
// 1.벽이 없는 경우 -> 부순횟수 그대로
// 2.벽이 있는 경우 -> 부순횟수 +1
// 같은 횟수 벽을 부수는 큐를 모두 탐색하면 현재큐를 다음큐로 최신화, 다음큐 빈큐로 최신화
//개념:
//: next_q = queue<int>(); //빈 큐를 넣어서 큐를 초기화
#define MAX 101
int n, m;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX]; 
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

;void bfs(int row, int col) {
	queue<pair<int,int>> q; // 현재 큐
	queue<pair<int, int>> next_q; // 다음 단계 큐
	// 큐에 푸쉬 , 방문 처리, 벽 부순횟수 저장
	q.push({ row,col }); visited[row][col] = 1;
	dist[row][col] = 0;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		// 4 방면 탐색
		for (int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];

			
			if (nrow <1 || nrow>n || ncol <1 || ncol>m) {continue;}// 범위조건
			if (visited[nrow][ncol] == 0) {
				// 벽이 없는 경우
				if (graph[nrow][ncol] == 0) { 
					q.push({ nrow,ncol }); visited[nrow][ncol] = 1;
					dist[nrow][ncol] = dist[row][col]; // 벽 부순횟수 가중 그대로
				}
				// 벽 있는 경우 
				if (graph[nrow][ncol] == 1) {
					next_q.push({ nrow,ncol }); visited[nrow][ncol] =1;
					dist[nrow][ncol] = dist[row][col] + 1; // 벽 부순 횟수 가중치 1 추가
				}
			}
		}
		// 현재 단계 모든 정점 탐색 후 다음 단계 큐로 최신화
		if (q.empty()) {
			q = next_q;
			next_q = queue<pair<int,int>>(); // 빈 큐를 대입해 큐 최신화
		}
	}
	
}
int main()
{
	//ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 이차원 그래프 입력 , 
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]); // 붙어있는 숫자라 scanf,cin 혼합 하면 안됨
		}
	}
	//bfs
	bfs(1, 1);

	printf("%d\n", dist[n][m]);
	return 0;
}
