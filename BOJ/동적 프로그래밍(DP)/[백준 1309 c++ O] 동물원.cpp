#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 1309 c++ O] 동물원 
// 문제:  2*N 배열에 가로로도 세로로도 붙어있지 않게 사자를 배치하는 경우의 수, 사자가 없는 경우도 포함
// 접근: 경우의수 구하기-> 왼전,dp -> 탑다운-> n번째 행의 우리에 사자를 배치하는 경우
// dp[n][0]:n번째 행에 사자가 없는 경우, dp[n][1]=n번째 행에 사자가 왼쪽 우리에만 있는경우,, dp[n][2]=n번째 행에 사자가 오른쪽 우리에만 있는 경우
// 점화식:
// dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]); 
// dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) ;
// dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) ;
// 시간 복잡도:O(n)
// 풀이: 
#define MAX 1000001
int n;
long long dp[MAX][3];
int mod = 9901;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	// 바텀업 dp 구현
	// dp점화식
	dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%mod; // n번째 우리에 사자 없으면 n-1번째 모든경우 가능
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%mod; // n번째 우리에 사자 왼쪽만 있으면 n-1번째에 사자 없거나+오른만 있거나
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%mod; // n번째 우리에 사자 오른만 있으면 n-1번째에 사자 없거나+왼만 있거나
	}
	// 경우의 수 출력
	cout << (dp[n][0] + dp[n][1]+ dp[n][2])%mod << '\n';
	return 0;
}
