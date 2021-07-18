#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 2193 c++ VO] 이친수 
// 문제: n 자리 이친수의 개수 구하기 
// 접근1: dp결과값으로 규칙 찾기 -> dp[n] = dp[n-1]+dp[n-2] => 이것도 정답
// 접근2: 2차원 dp : 0으로 끝나는 경우, 1로 끝난는 경우 => 정석 dp
// 풀이: 
// 점화식 dp 작성
// dp 점화식: 
// 0으로 끝나는 경우 dp[i][0] = dp[i-1][0] + dp[i-1][1]
// 1로 끝나는 경우 dp[i][1] = dp[i-1][0] 
// 정답 출력
// 주의
// : 범위 long long 으로 해야 함
#define MAX 91
int n;
vector<vector<long long>> dp(MAX,vector<long long>(2));

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축

	cin >> n;
	// dp 점화식: 
	// 0으로 끝나는 경우 dp[i][0] = dp[i-1][0] + dp[i-1][1]
	// 1로 끝나는 경우 dp[i][1] = dp[i-1][0] 
	dp[1][0] = 0; dp[1][1] = 1; 
	dp[2][0] = 1; dp[2][1] = 0;
	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // 0으로 끝나는 경우
		dp[i][1] = dp[i - 1][0]; // 1로 끝나는 경우
	}
	// 정답 출력
	long long answer = 0;
	for (int i = 0; i <=1; i++) {
		answer += dp[n][i];
	}
	cout << answer << '\n';
	
	return 0;
}
