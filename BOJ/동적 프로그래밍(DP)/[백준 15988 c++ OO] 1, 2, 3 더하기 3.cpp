#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 15988 c++ OO] 1, 2, 3 더하기 3 
// 문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
// 접근: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우 
// 1. i-1 에서 1 더한 것
// 2. i-2에서  2 더한 것
// 3. i-3 에서 3 더한것 3가지
// 점화식 : dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
// 풀이: 
// 주의: 1,2,3,더하기 문제에서 n의 값이 1000000으로 늘어나서 자료형을 longlong으로 바꿔주는 문제
#define MAX 1000001
int n,t;
long long dp[MAX];
long long mod = 1000000009;

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 바텀업 dp 구현
	// 점화식: dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= MAX - 1; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])% mod;
	}
	// 
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}
