#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 1463 c++ V] 1로 만들기
// 문제: -1./3,/2 3가지 계산을 통해 1로 만들 때 최소 연산 횟수를 구하라
// 접근: 완전 -> 시간초과 예상, 그리디 -> 최소 횟수 아닌 경우 있음  틀림
// 접근2: 3가지 조건 세분화, 중복 -> dp -> n부터 탑다운 점화식 -> 
// 1.n에서 -1 
// 2.2로 나눈 경우
// 3.3으로 나눈 경우  중 최소 연산횟수 +1
// dp점화식: dp[i] = min(dp(i-1),dp[i/2],dp[i/3])+1
// 풀이: 
// 점화식 초기값 1일때 초기화
// 점화식 으로 dp배열 만들기 dp[i] = min(dp(i-1),dp[i/2],dp[i/3])+1
#define MAX 1000001
long long n;
vector<int> dp(MAX);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> n;
	// dp점화식: dp[i] = min(dp(i-1),dp[i/2],dp[i/3])+1
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; // -1인 경우
		if (i % 2 == 0) { dp[i] = min(dp[i], dp[i / 2] + 1); } // 3d으로 나눈 경우
		if (i % 3 == 0) { dp[i] = min(dp[i],dp[i/3]+1); } // 2로 나눈 경우
	}

	cout << dp[n] << '\n';
	return 0;
}
