#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 03회차 04번 O] 미로찾기
문제:
접근: 
풀이:
	// 이차원 그래프 탐색
	//시작점 방문처리: 반복문 탐색으로 탐색할 때 에는 시작점을 방문처리 못하기 때문
	//1.dfs(행,열)
	//만약 목표지점이면 중단 및 카운트
	//1)4방향 탐색: 상우하좌
	//다음 행,열
	//만약 갈 수 있고, 방문 안했으면
	//방문처리 , dfs
	//방문처리 취소
시간복잡도: O()= 
개념:
*/
int cnt = 0;
int visit[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int graph[10][10] = {
	{1,1,1,1,1},
	{1,0,1,0,0},
	{1,0,1,1,1},
	{1,0,0,1,0},
	{1,1,1,1,1}
};

void dfs(int r, int c) {
	cout << r << " " << c << '\n';
	if (r == 4 && c == 4) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];

		if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) { continue; }
		if (graph[nr][nc] == 1 && visit[nr][nc] == 0) {
			visit[nr][nc] = 1;
			dfs(nr, nc);
			visit[nr][nc] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	// 이차원 그래프 탐색
	//시작점 방문처리: 반복문 탐색으로 탐색할 때 에는 시작점을 방문처리 못하기 때문
	//1.dfs(행,열)
	//만약 목표지점이면 중단 및 카운트
	//1)4방향 탐색: 상우하좌
	//다음 행,열 범위검사
	//만약 갈 수 있고, 방문 안했으면 
	//방문처리 , dfs
	//방문처리 취소
	visit[0][0] = 1;
	dfs(0, 0);
	cout << cnt << '\n';
	return 0;
}
