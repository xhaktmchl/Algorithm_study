#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 15989 c++ V] 1, 2, 3 더하기 4
문제:n을 1,2,3,의 합으로 순서다른 수는 제외하고 나타내는 방법의 수 구하기 
접근1: 완탐 재귀-> 재귀시 현재 더한 수보다 큰 수만 더하기 재귀해서 순서다른것 중복 제외 -> 시간초과 예상
시간복잡도: O(n^n) 10000^10000
접근2: dp -> 2차원 dp, 더하는 숫자가 오름차순이라 생각해서 순서다름 중복 제거
점화식 dp[i][j]= i숫자를 만드는데 마지막 더한 수가 j인 경우
1.dp[i][1] = dp[i - 1][1]; 마지막 수가 1 이면 그 전 i-1까지 1이하의 수만 가능
2.dp[i][2] = dp[i - 2][1] + dp[i - 2][2]; //마지막 수가 2 이면 그 전 i-2까지 2이하의 수만 가능
3.dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]; //마지막 수가 3 이면 그 전 i-3까지 3이하의 수만 가능
시간복잡도: O(n*3) = 10000*3
풀이1: 
바텀업 dp를 n 까지 먼저 계산,저장
테스트 케이스 마다 dp 출력
*/
#define MAX 10001
int t,n;
int dp[MAX][4] = { 0, };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 바텀업 dp 구현
	// 초기값 설정
	dp[0][1] = dp[0][2] = dp[0][3] = 0;
	dp[1][1] = 1; dp[1][2] = dp[1][3] = 0;
	dp[2][1] = dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i < MAX; i++) {
		dp[i][1] = dp[i - 1][1]; //마지막 수가 1 이면 그 전 i-1까지 1이하의 수만 가능
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2]; //마지막 수가 2 이면 그 전 i-2까지 2이하의 수만 가능
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]; //마지막 수가 3 이면 그 전 i-3까지 3이하의 수만 가능
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}
