#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 1495 c++ V] 기타리스트
// 문제: 
// 접근: 완전탐색 -> i번째 마다 +,- 하는 2가지 경우 -> 답은 맞으나 O(2^n) = 2^100 시간초과
// 접근2: dp -> 
// dp점화식 , 
// dp[i][j] = i번째 j 무게가 될 수 있는지 없는지 , j인덱스 = 무게
// 무게 뺀 경우 j - v[i+1]무게가 가능하면 가능한 무게에 표시 dp[i + 1][j - v[i+1]] = 1;
// 무게 더한 경우j + v[i+1]무게가 가능하면 가능한 무게에 표시 dp[i + 1][j + v[i+1]] = 1;
// 시간복잡도: O(n*m) = 100*1000 = 100만
// 풀이: 
// 바텀업 dp구현
#define MAX 1001
int n, s, m;
int v[MAX];
int dp[MAX][MAX];
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	// dp 
	dp[0][s] = 1; // 시작 볼륨 초기값
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) { 
			if (dp[i][j] == 0) { continue; }
			// i번째 j 볼륨이 가능하면 볼륨 더하거나, 빼는 경우 체크
			if (j - v[i+1] >= 0) { // 빼는 경우
				dp[i + 1][j - v[i+1]] = 1;
			}
			if (j + v[i+1] <=m) { // 더하는 경우
				dp[i + 1][j + v[i+1]] = 1;
			}
		}
	}

	for (int i = m; i >= 0; i--) {
		if (dp[n][i] == 1) { cout << i << '\n'; return 0; }
	}
	cout << -1 << '\n';
	return 0;
}



