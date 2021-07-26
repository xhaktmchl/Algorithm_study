#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 11054 c++ OV] 가장 긴 바이토닉 부분 수열
// 문제: 한 원소를 기점으로 양쪽에서 가장 긴 증가하는 부분수열(오름차순의 부분수열)의 길이를 구하는 문제
// 점근1: dp를 이용해 각 자리마다 나오는 증가하는 부분수열의 최대값 저장 왼쪽 오른쪽 부터 각 dp 구하고 그것의 합이 dp값
// 풀이: dp1[n]: n번째 까지 왼->오 증가하는 최대 부분수열의 길이
// dp2[n]: n번째 까지 오->왼 증가하는 최대 부분수열의 길이
// 수열의 길이라 각 자리의 dp는 초기값 1
// 왼쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 오른쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 각 dp의 2개 원소 값의 최댓값을 구함
// 주의: 왼,오른 중복되서 최댓값 -1 해야함
// 시간복잡도: O(n*n)
#define MAX 1001
int n;
int ar[MAX];
int dp1[MAX];
int dp2[MAX];
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
		dp1[i] = 1; 
		dp2[i] = 1;
	}
	// 앞->뒤 증가하는 부분수열
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (ar[i] > ar[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}//왼->오 감속하는 부분수열
	for (int i = n-1; i >=1; i--) {
		for (int j = n; j>i; j--) {
			if (ar[i] > ar[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	// 가장 긴 바이토닉 부분수열 구하기
	int maxN = 0;
	for (int i = 1; i <= n; i++) {
		int len = dp1[i] + dp2[i] - 1; // 겹치는 부분 -1 해야 함
		maxN = max(maxN, len);
	}
	cout << maxN << '\n';
	return 0;
}
