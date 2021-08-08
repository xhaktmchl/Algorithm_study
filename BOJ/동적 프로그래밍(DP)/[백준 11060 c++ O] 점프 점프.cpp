#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// 
// 문제: 일차원 배열의 최소 점프횟수 출력
// 접근: 완전탐색(재귀/dfs) -> -> 될 것 같음 , 시도는 안 해봄
// 접근2: 최댓값 -> dp -> 최소 점프횟수 저장하며 
// dp점화식 , 
// dp[i]= i까지의 최소 점프 횟수
// dp[i] = 0~i에서 i로 올 수 있는 dp중 최소 접프횟수
// 시간복잡도: O(n*n) = 1000*1000 = 100만
// 풀이: 
// 그래프 입력
// 바텀업 dp구현
#define MAX 1002
int n, m;
int a[MAX];
vector<int> dp(MAX,1001); // 최대값입 1000이라 1001로 초기화
bool visit[MAX];

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// 바텀업 dp 구현
	// dp점화식 , 
	// dp[i] = 0~i에서 i로 올 수 있는 dp중 최소 접프횟수
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[j] != 1001 && j + a[j] >= i) { // i로 점프 가능하면 
				dp[i] = min(dp[i], dp[j] + 1); // 최솟값 저장
			}
		}
	}
	if (dp[n] == 1001) { cout << -1 << '\n'; }
	else { cout << dp[n] << '\n'; }
	return 0;
}



