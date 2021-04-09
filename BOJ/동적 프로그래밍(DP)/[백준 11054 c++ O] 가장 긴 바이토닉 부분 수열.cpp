#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 11054 c++ O] 가장 긴 바이토닉 부분 수열
// 문제: 한 원소를 기점으로 양쪽에서 가장 긴 증가하는 부분수열(오름차순의 부분수열)의 길이를 구하는 문제
// 점근1: dp를 이용해 각 자리마다 나오는 증가하는 부분수열의 최대값 저장 왼쪽 오른쪽 부터 각 dp 구하고 그것의 합이 dp값
// 풀이: 왼쪽부터 오른쪽 부터 dp 2차원 배열을 생성
// 각 자리의 dp는 초기값 1
// 왼쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 오른쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 각 dp의 2개 원소 값의 최댓값을 구함
// 주의: 왼,오른 중복되서 최댓값 -1 해야함

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 1001

int n;
int ar[MAX];

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	// dp
	int dp[MAX][2];
	int max_dp = 0;
	// 왼쪽부터의 dp
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1; // 한개의 수는 길이 1
		for (int j = 0; j < i; j++) {
			if (ar[i] > ar[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}
	// 오른쪽부터의 dp
	for (int i = n-1; i >=0; i--) {
		dp[i][1]  = 1; // 한개의 수는 길이 1
		for (int j = n - 1; j > i; j--) {
			if (ar[i] > ar[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	// 최대dp 구하기
	for (int i = 0; i < n; i++) {
		max_dp = max(max_dp, dp[i][0] + dp[i][1] - 1); // i번째 2번 중복되서 1 빼야함
	}

	cout << max_dp;
	return 0;
}

