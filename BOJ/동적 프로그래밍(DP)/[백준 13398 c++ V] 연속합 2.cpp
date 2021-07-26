#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 13398 c++ V] 연속합 2
// 문제: 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합(수열에서 수를 하나 제거해도되고 않해도 됨)
// 점근1: 연속된 수,최대합 -> 완전탐색,그리디,dp -> 탑다운 dp로 생각해 각 자리마다 나오는 증가하는 연속수 최대값 저장
// 최대값 = 수를 빼지 않았을 때 최대 , 수를 뺐을 때 최대 중 최대값
// 1.수를 뺐을 때: i 번째 수를 하나 제거했을 때 최대 연속 합 = 왼->오 i-1번째 까지 최대 연속합 + 오->왼 i+1까지 최대 연속 합
// dp1[i]: 왼->오 연속된 수의 최대합, dp2[i]: 오->왼 연속된 수의 최대합, 
// i번째 수를 뺏을 때 최대 합= dp1[i-1]+dp2[i+1
//2. 수를 안뺏을 때
// dp1[i] = max(dp1[i], dp1[i - 1] + ar[i]);
// 풀이: 
// 수열 입력
// 왼->오 최대 연속합
// 오->왼 최대 연속합
// 시간복잡도: O(n)
// 숫자를 빼지 않은 경우 최대 합,// 한 숫자를 뺀 경우 최대 연속 합 중 최대값 출력
#define MAX 100002
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
	// 초기화 : 수의 합이기 때문에 각 자리 원소로 
	for (int i = 1; i <= n; i++) {
		dp1[i] = ar[i];
		dp2[i] = ar[i];
	}
	// 왼->오 최대 연속합
	for (int i = 2; i <= n; i++) {
		dp1[i] = max(dp1[i], dp1[i - 1] + ar[i]);
	}
	// 오->왼 최대 연속합
	for (int i = n-1; i >=1; i--) {
		dp2[i] = max(dp2[i], dp2[i + 1] + ar[i]);
	}

	// 숫자를 빼지 않은 경우 최대 합
	int maxN = dp1[1];
	for (int i = 1; i <= n; i++) {
		maxN = max(maxN, dp1[i]);
	}
	// 한 숫자를 뺀 경우 최대 연속 합
	for (int i = 2; i <= n-1; i++) {
		maxN = max(maxN, dp1[i - 1] + dp2[i + 1]);
	}
	cout << maxN << '\n';
	return 0;
}
