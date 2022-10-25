#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 06회차 02번 c++ O] combination
문제: 
접근:
풀이:
	//1.입력
	//2.바텀업 dp: n! 까지 값 메모이제이션
	//점화식: dp[i] = dp[i-1]*i
	//3.출력: nCk

시간복잡도: O()=
개념:
*/
int n, k;
long long dp[50];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n >> k;
	//2.바텀업 dp: n! 까지 값 메모이제이션
	//점화식: dp[i] = dp[i-1]*i
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * i;
	}
	//3.출력: nCk
	cout << dp[n] / (dp[k] * dp[n - k]) << '\n';
	return 0;
}
