#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [백준 1463 c++ VOO] 1로 만들기
// 문제: -1./3,/2 3가지 계산을 통해 1로 만들 때 최소 연산 횟수를 구하라
// 접근: 완전 -> 시간초과 예상, 그리디 -> 최소 횟수 아닌 경우 있음  틀림
// 접근2: 3가지 조건 세분화, 중복 -> dp -> n부터 탑다운 점화식으로 생각 -> 바텀업으로 구현
// 1.n에서 -1 
// 2.2로 나눈 경우
// 3.3으로 나눈 경우  중 최소 연산횟수 +1
// dp점화식: dp[i] = min(dp(i-1),dp[i/2],dp[i/3])+1
// 풀이: 
// 점화식 초기값 1일때 초기화
// 점화식 으로 dp배열 만들기 dp[i] = min(dp(i-1),dp[i/2],dp[i/3])+1#define MAX 1000001
#define MAX 1000001
int n;
int dp[MAX];

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	// 바텀업 dp 구현
	// dp점화식 : dp[n] = min(dp[n-1],dp[n/3],dp[n/2])+1
	dp[1] = 0; 
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i-1]+1;
		if (i % 2 == 0) { dp[i] = min(dp[i], dp[i / 2]+1); }
		if (i % 3 == 0) { dp[i] = min(dp[i], dp[i / 3]+1); }
	}
	cout << dp[n];
	return 0;
}
