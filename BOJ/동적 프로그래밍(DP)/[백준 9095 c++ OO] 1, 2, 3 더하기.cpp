#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 9095 c++ OO] 1, 2, 3 더하기
// 문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
// 접근: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우 
// 1.i-1 에서 1 더한 것
// 2. i-2에서  2 더한 것
// 3. i-3 에서 3 더한것 3가지
// 점화식 : dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
// 바텀업 dp 구현
// 풀이:

#define MAX 11
int n, t;
vector<int> dp(MAX);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 바텀업 dp 구현
	// dp점화식 : dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	// n까지 경우의 수 입력 및 출력
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
