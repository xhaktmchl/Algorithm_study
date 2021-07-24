#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 2225 c++ X] 제곱수의 합
// 문제: 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하라
// 접근 : 탑다운 dp: 
// n이 되기위한 합의 경우는
// dp[k][n]= k개를 이용해 합이n이 되는 경우의 수
// dp[k][n] = sum(dp[k-1][0],dp[k-1][1]...dp[k-1][n]) , 항의 개수가 1개 추가이므로 +1을 해주고 최소값을 비교
// 풀이: 
// dp점화식 을 3중 반복으로 실행하면서 최소항의 개수 갱신
// 주의: 다 더한 값에서 나눈 나머지를 저장해야 함
#define MAX 201
int n,k;
long long dp[MAX][MAX];
long long mod = 1000000000;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n>>k;
	
	// 바텀업 dp 구현
	// 점화식: dp[k][n] = sum(dp[k-1][0],dp[k-1][1]...dp[k-1][n]) 
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int q = 0; q <= j; q++) {
				dp[i][j] += dp[i - 1][j - q];
				dp[i][j] %= mod; // 주의: 다 더한 값에서 나눈 나머지를 저장해야 함
			}
		}
	}
	cout << dp[k][n] << '\n';
	return 0;
}
