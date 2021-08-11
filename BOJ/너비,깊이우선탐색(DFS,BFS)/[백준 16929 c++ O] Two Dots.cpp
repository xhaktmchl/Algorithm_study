#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 16929 c++ O] Two Dots
// 문제: 이차원 그래프에서 길이가 4 이상인 사이클의 존재 유무 출력
// 접근: 이차원 그래프 하나씩 탐색하며 싸이클 있는지 -> dfs/bfs -> bfs는 동시에 퍼져 나가기 때문에 사이클 확인 불가 -> dfs 선택
// 시간복잡도: O((n*m)*(n*m)) = 2500*2500 = 600만 , 가능
// 풀이: 
// 그래프 입력
// 모든정점 dfs탐색
// dfs탐색 중 시작 정점으로 돌아온 경우 점점의 수가 4개 이상이어야 사이클 만족
// 사이클 유무 출력
#define MAX 51
int n, m;
char graph[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int sr, sc;
string ans="No";

void dfs(int row, int col,int cnt) { // 행,렬, 정점 갯수
	visit[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		int nrow = row + dy[i];
		int ncol = col + dx[i];

		if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) { continue; } // 범위검사
		if (!visit[nrow][ncol] && graph[nrow][ncol] == graph[row][col]) { // 방문, 탐색가능 검사
			dfs(nrow, ncol,cnt+1);
		}
		// 시작 정점으로 돌아온 경우
		if (nrow == sr && ncol == sc && cnt >= 4) {
			ans = "Yes";
			return;
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
	// 모든정점 dfs 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visit, 0, sizeof(visit));
			sr = i; sc = j; // 시작 정점 저장
			dfs(i, j,1);
		}
	}
	cout << ans << '\n';
	return 0;
}



