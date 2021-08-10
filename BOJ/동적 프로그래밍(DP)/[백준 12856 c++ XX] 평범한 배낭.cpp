#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 12856 c++ XX] 평범한 배낭
// 문제: 냅색문제 . 가방에 넣을 수 있는 무게대비 최대 가치를 구하는 문제
// 접근:  재귀로 모든 경우의 수 탐색 -> O(2^100) 시간초과 안함
// 접근2: dp
// dp 점화식
// dp[i][j]= i번째 물건까지 j무게를 담았을 때 최대가치 
// dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); , i번째 물건을 안 넣은 것과 ,넣은 것 중 최대값 , 
// 풀이: 
// 물건 입력
// 바텀업 dp구현
#define MAX 100001
int n, k;
int w[101];
int v[101];
int dp[101][MAX];

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	// dp 점화식
    // dp[i][j]= i번째 물건까지 j무게를 담았을 때 최대가치 
	// dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); , i번째 물건을 안 넣은 것과 ,넣은 것 중 최대값 , 
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) { // 가방에 넣을 수 있으면
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}



