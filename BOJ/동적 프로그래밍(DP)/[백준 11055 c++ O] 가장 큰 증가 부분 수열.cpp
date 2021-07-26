#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 11055 c++ O] 가장 큰 증가 부분 수열
// 문제:  증가 부분 수열 중에서 합이 가장 큰 것을 구하라
// 접근1: 최댓값(완전탐색,그리디,dp) -> 탑다운 dp로 생각
// dp[n] : n번째 까지의 증가하는 최대 부분수열의 합
// 가장 긴 증가하는 부분수열에서 수열의 합을 더해주는 것이 차이
// n번째 부분수열의 원소가 n보다 작은 수열의 클 때에만 비교
// dp[i] = if (ar[j] < ar[i]) max(dp[i-1] + ar[i],dp[i-2]+ar[i], ,,, dp[1]+ar[i]);
// 초기화 자기 숫자로 초기화
// 풀이: 
// 바텀업 dp 구현
// 시간복잡도: O(n*n)
// 개념
//: max_element(dp, dp + n): max_element(시작주소,끝주소) 최대값의 주소를 반환
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
	for (int i = 1; i <= n; i++) {
		dp[i] = ar[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (ar[j] < ar[i]) {
				dp[i] = max(dp[i], dp[j] + ar[i]);
			}
			
		}
	}
	// 최대 증가 부분수열의 합 출력
	// max_element 함수를 이용하면 최댓값 바로 구함: max_element(시작주소,끝주소)
	cout << *max_element(dp+1, dp + n+1) << '\n';
	/*	int maxN = 0;
	for (int i = 1; i <= n; i++) {
		maxN = max(maxN, dp[i]);
	}
	cout << maxN << '\n';*/

	return 0;
}
