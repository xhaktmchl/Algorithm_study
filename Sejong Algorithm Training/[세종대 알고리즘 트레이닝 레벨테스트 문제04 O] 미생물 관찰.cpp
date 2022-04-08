#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 레벨테스트 문제04 O] 미생물 관찰
문제: 맵이 주어지고 A,B각 개체의 마릿수, 객체의 최대크기 출력
접근1: 완탐,dfs
시간복잡도: O(n*m)=40000??
*/
int n, m;
string map[210];
bool visit[210][210];
int cntA = 0, cntB = 0, cntC=0;
int dx[4] = { 0,1,0,-1 };// 상우하좌
int dy[4] = { -1,0,1,0 };
int maxN = 0;
int cnt = 0;
//dfs
// 1.방문처리, 개체의 크기 카운트
// 객체의 최댓값 비교

// 2.dfs재귀
// 4방면 탐색
// 범위검사
// 방문하지 않앗고 같은 개체 세포이면
// dfs재귀
void dfs(int row, int col) {
	visit[row][col] = 1; cnt++;
	maxN = max(maxN, cnt);
	//cout << "[" << row << "," << col << "]" << '\n';

	for (int i = 0; i < 4; i++) {
		int rr = row + dy[i];
		int cc = col + dx[i];
		if (rr < 0 || rr >= n || cc < 0 || cc >= m) { continue; }
		if (visit[rr][cc] == 0 && map[row][col]==map[rr][cc]) {
			dfs(rr, cc);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.맵 입력
	// string배열로
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	// 2.완탐
	// 1)방문하지 않았으면 dfs
	// 개체수 카운트
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j]!='_') { // 빈 공간 예외처리
				cnt = 0; // 각 개채의 크기 초기화
				if (map[i][j] == 'A') {
					cntA++;
				}
				else if(map[i][j]=='B') {
					cntB++;
				}
				dfs(i, j);
			}
		}
	}
	// 3.출력
	// 각 개체수
	// 개체크기 최대값
	cout << cntA << " " << cntB<<'\n';
	cout << maxN << '\n';
	return 0;
}
