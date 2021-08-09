#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10942 c++ V] 팰린드롬?
// 문제: 수열을 입력받고 원하는 구간의 수가 팰린드롬인지 출력
// 접근: 완전탐색 -> 각 구간 입력 받을 때 마다 팰린드롬인지 검사 -> 답은 맞으나 n*n*n= 시간초과
// 접근2: dp -> 구간1 이 팰린드롬이면 -> 양 옆에 같은수 붙으면 팰린드롬 .... 반복 
// dp점화식 , 
// dp[i][j] = (i,j) 구간의 수가 팰린드롬인지
// 1구간은 무조건 팰린드롬
// 길이가 2인 구간은 수가 같아야 팰린드롬
// 길이 >=3  부터는 (i+1,j-1) 구간의 수가 같고 양 옆 수가 같으면 팰린드롬 
// dp[i][j] = if(dp[i+1][j-1] ==1 && a[i] == a[j]){ 1 }
// 시간복잡도: O(n*n+m) = 2000*2000+100만 = 500만
// 풀이: 
// 바텀업 dp구현
#define MAX 2001
int n, m;
int a[MAX];
int dp[MAX][MAX]; // 최대값입 1000이라 1001로 초기화

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
	// dp[i][j] = if(dp[i+1][j-1] ==1 && a[i] == a[j]){ 1 }
	// 길이=1
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	// 길이=2
	for (int i = 1; i+1 <= n; i++) {
		if(a[i] == a[i+1]){ dp[i][i + 1] = 1; }
	}
	// 길이>=3
	for (int i = 2; i <= n; i++) { // 구간 길이
		for (int j = 1; i+j <= n; j++) { // 현재 위치
			if (dp[j + 1][j+i - 1] == 1 && a[j] == a[j+i]) {
				dp[j][j + i] = 1;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << dp[start][end] << '\n';
	}
	return 0;
}



