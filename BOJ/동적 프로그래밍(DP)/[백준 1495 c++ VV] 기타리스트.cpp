#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 1495 c++ VV] 기타리스트
문제:
접근: 완전탐색 -> i번째 마다 +,- 하는 2가지 경우 -> 답은 맞으나 O(2^n) = 2^100 시간초과
접근2: dp ->
dp점화식 ,
dp[i][j] = i번째 j 무게가 될 수 있는지 없는지 , j인덱스 = 무게
볼륨 뺀 경우 j - v[i+1]무게가 가능하면 가능한 무게에 표시 dp[i + 1][j - v[i+1]] = 1;
볼륨 더한 경우j + v[i+1]무게가 가능하면 가능한 무게에 표시 dp[i + 1][j + v[i+1]] = 1;
시간복잡도: O(n*m) = 100*1000 = 100만
풀이:
볼륨 리스트 입력
바텀업 dp구현
마지막 곡 최대볼륨 탐색
*/
#define MAX 101
int n, s, m;
int v[MAX];
bool dp[MAX][1001];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {//볼륨 목록 입력
		cin >> v[i];
	}
	// 바텀업 dp 구현
	dp[0][s] = 1; // 초기 가능한 볼륨 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j - v[i+1] >= 0) { dp[i+1][j - v[i+1]] = 1; } // 볼륨을 뺀 경우
				if (j + v[i+1] <= m) { dp[i+1][j+v[i+1]] = 1; } // 볼륨을 더한 경우
			}
		}
	}
	// 최댓값 구하기
	int maxN = -1;
	for (int j = 0; j <= m; j++) {
		if (dp[n][j]) { maxN = max(maxN, j); }
	}
	if (maxN == -1) { cout << -1 << '\n'; }
	else { cout << maxN << '\n'; }
	return 0;
}
