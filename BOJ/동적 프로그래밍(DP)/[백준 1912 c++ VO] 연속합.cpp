#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 1912 c++ VO] 연속합
// 문제: 최대 연속된 부분수열의 합의 최댓값 구하기
// 접근1: 최대 부분수열의 합의 최댓값 알고리즘 적용
// 원소를 계속해서 더해간다
// 더한 값이 최댓값이면 최댓값 갱신
// 더함값이 음수면 0으로 초기화 하고 더해간다.
// 음수만 있는 경우는 음수 중 최댓값을 찾아서 예외처리 해준다
// 풀이1: 연속합 알고리즘을 이용해서 풀기 
// 수열 입력
// 최대 부분수열의 합 구하고
// 만약 음수만 있는 경우가 아니면 최댓값 출력
// 음수만 있는 경우는 음수중 최댓값 출력
// 풀이2: dp로 풀기(이 풀이가 좀 더 좋다고 생각)
// dp[i]: i번째 수로 끝나는 가장 큰 연속합 저장
// 점화식: dp[i] = max(dp[i],dp[i-1]+ar[i]) 로 i까지 최대 연속합 저장
// 한번더 탐색하며 최대 연속합 구하기
#define MAX 1000001
int n;
vector<int> ar(MAX);
vector<int> dp(MAX);
int maxN=-1001,sum=0;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	// 수열 입력
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	// 바텀업 dp 구현
	// dp[i]: i번째 수로 끝나는 가장 큰 연속합 저장
	// 점화식: dp[i] = max(dp[i],dp[i-1]+ar[i])
	dp = ar;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + ar[i]);
		if(dp[i] < dp[i-1]+ar[i]){}
	}

	// 최댓값 구하기
	for (int i = 0; i < n; i++) {// 음수 중 최댓값 추출
		maxN = max(maxN, dp[i]);
	}
	cout << maxN << '\n';
	return 0;
}
