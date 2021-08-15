#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 16197 c++ V] 두 동전 
// 문제: 이차원 그래프에서 동전을 하나만 떨어뜨리는데 최소이동 횟수 구하기
// 접근: 이차원 그래프 이동 -> dfs/bfs/ -> 시도는 안해봄
// 접근2: 이차원 그래프 이동 -> 완탐 재귀 -> 떨어지는 조건 = 일단 이동하고 범위 검사 
// 시간복잡도: O(n*m + 4^10) = 400+ 100만 
// 풀이: 
// 그래프 입력 , 동전 위치 저장
// 재귀 그래프 탐색
// 1.가능한 경우 : 동전이 하나만 떨어짐
// 2.불가능 : 동전 둘 다 떨어짐 , 둘 다 벽으로 이동 , 10번 초과 이동
// 3. 4방향 재귀: 동전1만 이동/ 동전 2만 이동/ 동전 둘 다 이동
#define MAX 21
int n, m;
char graph[MAX][MAX];
vector<int> ro;
vector<int> co;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int minN = 11;

void re(int r1, int c1, int r2, int c2, int cnt) {
	// 불가능, 10번 초과 이동
	if (cnt > 10) { return; }
	// 종료조건, 동전 1만 떨어지기
	if ((r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) && (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m)) {
		minN = min(minN, cnt);
		return;
	}// 종료조건, 동전2만 떨어짐
	if ((r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) && (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m)) {
		minN = min(minN, cnt);
		return;
	}// 불가능 , 동전 둘 다 떨어짐
	if ((r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) && (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)) {
		return;
	}
	// 불가능, 둘 다 벽으로 이동한 경우
	if (graph[r1][c1] == '#' && graph[r2][c2] == '#') { return; }
	
	// 4방향 재귀 탐색
	for (int i = 0; i < 4; i++) {
		// 동전1 벽으로 이동한 경우
		if (graph[r1 + dy[i]][c1 + dx[i]] == '#' && graph[r2 + dy[i]][c2 + dx[i]] != '#') {
			re(r1, c1, r2 + dy[i], c2 + dx[i], cnt + 1);
		}
		// 동전2 벽으로 이동한 경우
		else if (graph[r1 + dy[i]][c1 + dx[i]] != '#' && graph[r2 + dy[i]][c2 + dx[i]] == '#') {
			re(r1 + dy[i], c1 + dx[i], r2 , c2 , cnt + 1);
		}// 둘 다 이동
		else {
			re(r1 + dy[i], c1 + dx[i], r2 + dy[i], c2 + dx[i], cnt + 1);
		}
	}

}

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if(graph[i][j] == 'o'){
				ro.push_back(i); // 행 저장
				co.push_back(j);// 열 저장
			}
		}
	}
	// 재귀 이차원 그래프 탐색
	re(ro[0], co[0], ro[1], co[1],0); // 동전1,2 행,렬  
	if (minN == 11) {	cout << -1 << '\n';}
	else { cout << minN << '\n';}
	return 0;
}



