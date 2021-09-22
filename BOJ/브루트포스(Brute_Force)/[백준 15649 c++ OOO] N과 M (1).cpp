#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 15649 c++ OOO] N과 M (1)
접근1: dp[n] = dp[n-1]+dp[n-2]+dp[n-3] -> 이번엔 완전탐색으로 구현
접근2: 완전탐색 -> 재귀dfs -> 재귀중간 순열 체크하면 방문한것 초기화 해야함
시간복잡도: n*(n-1)*...1 가지 경우의 수 = O(n!)
풀이1:
수 입력
dfs재귀로 인자 재귀 내에 수열배열 넘겨주며 따로 저장 모든 수열 탐색
풀이2:
수 입력
재귀로 전역배열로 수열 저장하고 수열의 인덱스 를 넘겨주며 저장 모든 수열 탐색
*/
#define MAX 10
int n, m;
bool visit[MAX];
int a[MAX];
// 완탐 재귀
void re(int idx) { // 현재까지 고른 숫자의 갯수
	// 종료조건, 가능한 경우
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}cout << '\n';
		return;
	}
	// 불가능한 경우: 없음

	//재귀 다른 수 탐색
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = 1; a[idx] = i;
			re(idx + 1);
			visit[i] = 0; // 벡터로 수열 만들면 팝해주는것 추가해야됨
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	re(0);
	return 0;
}
