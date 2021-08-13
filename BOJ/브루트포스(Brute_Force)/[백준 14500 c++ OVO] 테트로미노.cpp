#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 14500 c++ OVO] 테트로미노
// 문제: 가능한 5종류의 테트로미노 각 칸의 합의 최대값 구하기
// 접근: 이차원 그래프탐색 -> 칸의 개수 4개 -> depth가 4인 dfs 생각 ->  근데 ㅗㅓㅏㅜ 는 dfs로 탐색 불가능한 모양 이어서 따로 계산 
// -> 알고보니 4방향 탐색하는데 방문초기화 하고 가능한 모든 길이 4 인 것 탐색하면서 방문 했던 곳 다시 방문하므로  완전탐색 재귀이다.
// 시간복잡도: O(n*m*4^4) = 500*500*16*16 = 약6400만 따라서 완전탐색 가능
// 풀이: 
// 그래프 입력
// 뎁스가4 인 완전탐색 재귀/dfs로 테트로 미노의 최댓값 갱신
// ㅏㅓㅗㅜ 모양은 중심칸의 인덱스 조건 걸고 각자 계산 후 최댓값 갱신
// 최댓값 출력
#define MAX 21
int n, m;
int graph[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxN;

void re(int r, int c, int cnt, int sum) {
	visit[r][c] = 1; cnt++;
	sum += graph[r][c];

	// 종료조건, 4개 탐색 완료시
	if (cnt == 4) {
		maxN = max(maxN, sum);
		return;
	}

	//4 방향 탐색 재귀
	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m) { continue; } // 범위검사
		if (visit[nr][nc] == 0) { // 방문검사
			re(nr, nc, cnt, sum);
			visit[nr][nc] = 0; // 재귀 방문 초기화
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 나머지 테트로 미노 완탐 재귀
			memset(visit, 0, sizeof(visit));
			re(i, j, 0, 0);

			// ㅏㅓㅗㅜ
			// ㅏ
			if (i > 0 && i < n - 1 && j < m - 1) {
				maxN = max(maxN, graph[i][j] + graph[i - 1][j] + graph[i + 1][j] + graph[i][j + 1]);
			}
			// ㅓ
			if (i > 0 && i < n - 1 && j >0) {
				maxN = max(maxN, graph[i][j] + graph[i - 1][j] + graph[i + 1][j] + graph[i][j - 1]);
			}
			// ㅗ
			if (i > 0 && j > 0 && j < m - 1) {
				maxN = max(maxN, graph[i][j] + graph[i - 1][j] + graph[i][j + 1] + graph[i][j - 1]);
			}
			// ㅜ
			if (i < n - 1 && j > 0 && j < m - 1) {
				maxN = max(maxN, graph[i][j] + graph[i + 1][j] + graph[i][j + 1] + graph[i][j - 1]);
			}
		}
	}
	cout << maxN << '\n';
	return 0;
}



