#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 7576 c++ VO] 토마토 
// 문제: 이차원 그래프에 주어진 토마토가 모드 익는데 걸리는 최소일 수 구하기
// 접근: 이차원 그래프 최소일수 -> bfs
// 이동시간를 저장하는 dist배열 따로 저장
// 처음 시작하는 위치를 모두 추출한 다음 bfs 시작하는게 특징
// 시간복잡도: ??
// 풀이 :
// 그래프 입력
// 익은 토마토의 위치 큐에 모두 삽입
// 익은 토마토의 큐를 이용해서 bfs 탐색
// 탐색하며 걸린 일 수 저장
// 탐색이 끝난 후 안익은 토마토가 있으면 -1출력
// 아니면 토마토가 익는데 걸린 시간출력
#define MAX 1001
int m, n;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[MAX][MAX];
queue<pair<int,int>> q;

void bfs() {

	while (!q.empty()) {
		// 현재 위치
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		//4방면 탐색
		for (int i = 0; i < 4; i++) {
			int currow = row + dy[i];
			int curcol = col + dx[i];
			
			if (currow < 0 || currow >= n || curcol < 0 || curcol >= m) { continue; }
			if (visited[currow][curcol] == 0 && graph[currow][curcol] == 0) {
				// 큐에 푸쉬 및 방문처리
				q.push({ currow,curcol }); visited[currow][curcol] = 1;
				dist[currow][curcol] = dist[row][col] + 1;
			}
		}
	}
}


int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//그래프 입력
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	// 탐색
	// 익은 토마토 위치 파악
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 1) {
				q.push({ i,j }); visited[i][j] = 1;
				dist[i][j] = 0;
			}
		}
	}

	// bfs
	bfs();

	// 최소일수, 불가능 예외 검사
	int maxN = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && graph[i][j] == 0) { cout << -1 << '\n'; return 0; } // 불가능한 경우
			maxN = max(maxN, dist[i][j]);
		}
	}
	cout << maxN << '\n';
	return 0;
}
