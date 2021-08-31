#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2667 c++ VOOO] 단지번호붙이기 
// 문제: 각 단지별로 단지의 갯수와 단지마다의 아파트 갯수 구하기
// 접근: 각 단지의 행렬 구역 탐색 -> 2차원 그래프 dfs또는 bfs -> dfs선택
// 시간복잡도: O(n*n+ 간선의 갯수)?? 
// 풀이: 
// 이차원 배열과 방문배열 저장하고 dfs로 단지 모든 정점 탐색
// 방문 않한 단지 있는 곳만 탐색
// 주의: 
//: 여기선 모든 정점 1번씩만 방문하므로 방문배열 초기화 필요없음
#define MAX 26
int gr[MAX][MAX];
int n, cnt = 0;
bool visit[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> ans;

void dfs(int r, int c) {
	visit[r][c] = 1; cnt++; // 방문처리
	// 4방향 탐색
	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr <= 0 || nr > n || nc <= 0 || nc > n) { continue; } // 범위검사
		if (!visit[nr][nc] && gr[nr][nc] == 1) { // 방문검사, 단지검사
			dfs(nr, nc);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	//cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 그래프 입력
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d",&gr[i][j]);
		}
	}
	// dfs
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && gr[i][j] == 1) { // 방문하지 않앗는데 단지있으면
				dfs(i, j);
				c++;
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}
	// 출력
	printf("%d\n", c);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
