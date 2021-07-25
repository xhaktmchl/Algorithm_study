#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 1932 c++ VO] 정수 삼각형 
// 문제: 정수 삼각형의 각 층에서 하나를 선택해 더할 때 최댓값 구하기, 선택한 수의 왼쪽 아래와 오른쪽 아래의 수만 선택가능
// 접근1: 최댓값(완전탐색,그리디,dp) -> 탑다운 dp로 생각
// dp[n][i] : n번째 층의 i번째 숫자까지의 최대 합
//-> 1.n번째 층의 1번째 수는 자신의 오른쪽 위 숫자에서만 올 수 있음= dp[i][j] = dp[i-1][1] + ar[i][1];
//-> 2.n번째 층의 2~n-1번째 수는 양 대각석 위의 수에서 올 수 있음= dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j]) + ar[i][j];
//-> 3.n번째 층의 n번째 수는 자신의 왼쪽 위 숫자에서만 올 수 있음= dp[i][j] = dp[i - 1][j-1] + ar[i][j];
// 풀이: 
// 바텀업 dp 구현
// 시간복잡도: O(n*n)
#define MAX 501
int n;
int ar[MAX][MAX];
int dp[MAX][MAX];
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 정수 삼각형 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> ar[i][j];
		}
	}
	// 바텀업 dp 구현
	// dp점화식
	dp[1][1] = ar[1][1];
	dp[2][1] = dp[1][1] + ar[2][1]; dp[2][2] = dp[1][1] + ar[2][2];
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if(j==1){dp[i][j] = dp[i-1][1] + ar[i][1]; }//n번째 층의 1번째 수는 자신의 오른쪽 위 숫자에서만 올 수 있음
			if(j>=2 && j<=i-1){
				dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j]) + ar[i][j];// n번째 층의 2~n-1번째 수는 양 대각석 위의 수에서 올 수 있음
			}
			if(j == i){ dp[i][j] = dp[i - 1][j-1] + ar[i][j]; }//n번째 층의 n번째 수는 자신의 왼쪽 위 숫자에서만 올 수 있음
		}
	}
	// 최대값 출력
	int maxN = 0;
	for (int i = 1; i <= n; i++) {
		maxN = max(maxN, dp[n][i]);
	}
	cout << maxN << '\n';
	return 0;
}
