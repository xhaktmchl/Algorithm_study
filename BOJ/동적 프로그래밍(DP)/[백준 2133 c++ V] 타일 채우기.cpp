#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 2133 c++ V] 타일 채우기
// 문제: 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수
// 접근1: 경우의 수 -> 완전탐색,dp -> 탑다운 dp로 생각
// 점화식
// dp[n] : n번째 까지 만들 수 있는 경우의 수
// dp[i] = 3 * dp[i - 2] + 2*dp[i-4] + 2*dp[i-6] + ,,,,
// i가 짝수 번째 마다 dp의 갯수가 늘어나므로 반복문 -> 2중반복
// i가 홀수면 타일 못만듦-> 모두 0
// 주의: 타일의 종류가 크기가 커질 수록 계속 늘어나는 것을 캐치하는것이 어려움
// 풀이: 
// n입력
// 바텀업 점화식 구현
// 최댓값 출력
// 시간복잡도: O(n*n)
#define MAX 31
int n;
long long dp[MAX];
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	
	// 바텀업 dp 구현
	// dp점화식
	// 초기화 : n이 홀수일땐 모두 0개
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	for (int i = 4; i <= n; i++) {
		dp[i] = 3 * dp[i - 2]; // dp[i] = 3 * dp[i - 2] + 2*dp[i-4] + 2*dp[i-6] + ,,,,
		for (int j = 2; i - 2 * j >= 0;j++) {
			dp[i] += dp[i - 2*j] * 2 ;
		}
	
	}
	cout << dp[n] << '\n';
	return 0;
}
