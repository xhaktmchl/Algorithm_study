#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 11057 c++ O] 오르막 수 
// 문제:  인접한 수가 같거나 증가하는 수로 구성된 수를 오르막 수라고 한다. n자리의 오르막 수의 갯수 구하기
// 접근: 갯수 구하기(완전탐색/dp) -> 탑다운 dp 
//-> n번째 자리가0 이면 n-1자리가 0인
//-> n번째 자리가1 이면 n-1자리가 0,1
// ... -> n번째 자리가9 이면 n-1자리가 0~9 이다.
// 이차원 dp[n][i]: n번째 자리의 수가 i인 오르막 수의 갯수
// 점화식:
// dp[i][0] = dp[i - 1][0]
// dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) ;
//  ... dp[i][9] = (dp[i - 1][0] + dp[i - 1][1]+,,dp[i-1][9] ;
// 시간 복잡도:O(n*n) ? 헷갈림
// 풀이: 
#define MAX 1001
int n;
long long dp[MAX][10];
int mod = 10007;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	// 바텀업 dp 구현
	// dp점화식
	// dp[i][0] = dp[i - 1][0]
    // dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) ;
	//  ... dp[i][9] = (dp[i - 1][0] + dp[i - 1][1]+,,dp[i-1][9] ;
	for (int i = 0; i <= 9; i++) { dp[1][i] = 1; }
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int q = 0; q <= j; q++) {
				dp[i][j] += dp[i - 1][q];
			}
			dp[i][j] %= mod;
		}
	}
	// 오르막 수의 갯수 출력
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	cout << sum % mod << '\n';
	return 0;
}
