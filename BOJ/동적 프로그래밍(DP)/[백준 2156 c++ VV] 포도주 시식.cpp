#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 2156 c++ VV] 포도주 시식
// 문제: 연속 3개를 마시지 않으면서 n개의 포도주를 마셔서 포도주 합의 최댓값 구하기
// 접근1: dp로 점화식 구하고 그때그때의 최댓값 저장
// 풀이: 포도주 입력
// n번째 포도주합의 최댓값
// dp 점화식
// 1. n번째 0번연속 마시기  dp[n - 1] 까지 최댓값 더하기
// 2. n번째 1번연속 마시고  dp[n-2] 까지 최댓값 더하기
// 3. n번째 2번 연속 마시고 dp[n-3] 까지 최댓값 더하기
// dp[i] = max(dp[i - 1],dp[i - 2] + ar[i], dp[i - 3] + ar[i - 1] + ar[i]));
// 바텀업 dp 구현
// 시간복잡도: O(n)
// 개념: 3개 이상 비교 max({1,2,3}) 중괄호로 이용 가능
#define MAX 10001
int n;
int ar[MAX];
int dp[MAX];
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	// 바텀업 dp 구현
	// dp점화식
	//dp[i] = max(dp[i - 1], dp[i - 2] + ar[i], dp[i - 3] + ar[i - 1] + ar[i]));
	dp[1] = ar[1];
	dp[2] = ar[1] + ar[2];
	dp[3] = max(dp[2], max(dp[1] + ar[3], ar[2] + ar[3]));
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + ar[i], dp[i - 3] + ar[i - 1] + ar[i])); // n번째에 0번, 1번,2번 연속마신 것 중 최대값
	}
	cout << dp[n] << '\n';
	return 0;
}
