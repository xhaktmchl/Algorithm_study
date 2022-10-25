#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 06회차 04번 백준 1010 c++ X] 다리 놓기
문제:
접근: 결국 m개 중에서 n개를 선택하는 경우의 수를 구하는 것. => 콤비네이션 계산 값이 너무 커서 에러 남
접근2: dp
풀이:
	//1.입력
	//2.상향식 dp[i][j] = dp[i-1][j-1]+...+dp[i-1][1]
	//3.출력

시간복잡도: O()=
개념:
*/
int t;
long long dp[50][50];
int n, m;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> t;
	
	//2.상향식 dp[i][j] = dp[i-1][j-1]+...+dp[i-1][1]
	for (int i = 1; i < 30; i++) {
		dp[1][i] = i;
	}
	for (int i = 1; i < 30; i++) {
		for (int j = i; j < 30; j++) {

			for (int k = j - 1; k >= 1; k--) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	//3.출력
	while (t-- > 0) {
		cin >> n >> m;

		cout << dp[n][m] << '\n';
	}
	return 0;
}
