#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 11058 c++ X] 크리보드 
문제: 
접근: 완전탐색 -> i번째 마다 버튼 누르는 4가지 경우 -> 답은 맞으나 O(4^n) = 4^100 시간초과
접근2: dp ->
dp점화식 ,
dp[i] = i번째 까지 최대 A 갯수 , max(A하나 추가한 것, dp[i-3]부터 i까지 계속 붙여넣기 , 같은 방법으로 dp[i-4]....dp[4] 까지 붙여너히기) 중 최대값
시간복잡도: O(n*n) = 100*100 
질문: 다른 코드를 참조하면 DP[i] = max({ DP[i - 1] + 1, DP[i - 3] * 2, DP[i - 4] * 3, DP[i - 5] * 4 }) 처럼 
1.A하나 추가한 것 이랑 붙여넣기 한것이 i - 3, i-4,i-5 세 범위까지만 하는지 이해 안감
풀이:
바텀업 dp 구현
dp초기값 설정
나머지 dp 구현
n번째 최댓값 출력
*/
#define MAX 101
int n;
long long dp[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	dp[0] = 0; // 버튼 누르지 않은 경우
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; // A하나 추가
		for (int j = 3; j <= i - 3; j++) { // i-j부터 4까지 붙여넣기
			dp[i] = max(dp[i], dp[i - j] * (j-1)); 
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
