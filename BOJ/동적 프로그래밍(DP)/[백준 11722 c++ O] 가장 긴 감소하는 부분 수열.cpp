#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 11722 c++ O] 가장 긴 감소하는 부분 수열
// 문제:  가장 긴 감소하는 부분 수열의 길이를 구하라
// 접근1: 최댓값(완전탐색,그리디,dp) -> 탑다운 dp로 생각 -> 가장 긴 증가하는 부분수열의 길이에서 부호만 바꿔줌 응용
// dp[n] : n번째 까지의 감소하는 최대 부분수열 길이
// 길이 이므로 dp 모두 1로 초기화
// n번째 부분수열의 원소가 그 전의 원소보다 작을 때에만 비교
// dp[i] = if (ar[j] > ar[i]) max(dp[i-1]+1,dp[i-2]+1, ,,, dp[1]+1);
// 풀이: 
// 바텀업 dp 구현
// 시간복잡도: O(n*n)
// 개념
//: max_element(dp, dp + n): max_element(시작주소,끝주소) 최대값의 주소를 반환
//:dp가 벡터일 때 max_element(dp.begin(), dp.end()): max_element(시작주소,끝주소) 최대값의 주소를 반환
#define MAX 1001
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
	// 수열의 길이이므로 모두 1로 초기화
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (ar[j] > ar[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			
		}
	}
	// 가장 긴 감소하는 부분수열의 길이 출력
	cout << *max_element(dp + 1, dp + n + 1) << '\n';

	return 0;
}
