#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 2193 c++ VOO] 이친수 
// 문제: n 자리 이친수의 개수 구하기 
// 접근1: dp결과값으로 규칙 찾기 -> 못찾음
// 접근2: 2차원 dp : 0으로 끝나는 경우, 1로 끝난는 경우
// 풀이: 
// 점화식 dp 작성
// dp 점화식: 
// 0으로 끝나는 경우 dp[i][0] = dp[i-1][0] + dp[i-1][1]
// 1로 끝나는 경우 dp[i][1] = dp[i-1][0] 
// 정답 출력
#define MAX 91
int n;
long long dp[MAX][2];

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	// 바텀업 dp 구현
	// dp 점화식: 
	// 0으로 끝나는 이친수( :dp[i][0] = dp[i - 1][1] + dp[i - 1][0]; 
	// 1로 끝나는 이친수 : dp[i][1] = dp[i - 1][0];
	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];// 0으로 끝나는 경우
		dp[i][1] = dp[i - 1][0]; // 1로 끝나는 경우
	}
	// 이친수 갯수 출력
	cout << dp[n][0] + dp[n][1] << '\n';
	return 0;
}
