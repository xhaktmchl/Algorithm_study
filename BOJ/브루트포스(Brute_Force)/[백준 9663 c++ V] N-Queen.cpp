#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 9663 c++ V] N-Queen
// 문제: 이차원 그래프에 모든 행에 퀸을 놓는 방법의 수
// 접근: 이차원 그래프 모든 방법 -> 완탐,dfs,bfs -> 모든 경우이므로 완탐 선택 -> 각 행 열마다 퀸 놓을 수 있는지 백트랙킹
// 시간복잡도: ??
// 풀이: 
// 각 행열에 퀸 놓고 검사
#define MAX 16
int n,ans=0;
bool visit[MAX][MAX];
// 퀸 유무 검사
bool check(int r, int c) {
	// 같은 열 퀸 유무 검사
	for (int i = 0; i < r; i++) {
		if (visit[i][c]) { return false; }
	}
	// 대각선
	for (int i = 1; i <= n;i++) {
		int rtp = r - i;
		int lc = c - i, rc = c + i;
		if (rtp >= 0 && lc >= 0 && lc < n) {// 왼위 대각선 검사
			if (visit[rtp][lc]) {
				return false;
			}
		}
		if (rtp >= 0 && rc >= 0 && rc < n) {// 오른 위 대각선 검사
			if (visit[rtp][rc]) {
				return false;
			}
		}
	}
	return true;
}

void re(int row) {
	// 종료조건, 가능한:모든 행에 퀸 존재
	if (row == n) { 
		ans++;
		return;
	}
	// 불가능: 백트래킹으로 미리 조건 있음

	//같은 행의 모든 열 퀸 놓을 수 있는지 재귀
	for (int col = 0; col < n; col++) {
		visit[row][col] = 1;
		if (check(row, col)) {
			re(row + 1);
		}
		visit[row][col] = 0; // 재귀이므로 방문 초기화
	}
}

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	re(0);
	cout << ans << '\n';
	return 0;
}
