#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 10844 c++ VVO] 쉬운 계단 수 
// 문제: n 자리의 계단 수의 개수를 1000000000로 나눈 나머지를 구하는 문제
// 접근1: 직접 갯수 세서 개수간의 규칙으로 점화식 찾아서 찍었는데 틀림
// 점근2: n-1 의 계단수와 n의 계단수의 규칙 찾으려 함 , 맨 왼쪽 시작하는 수를 첫째 자리 수라고 보고 생각
// 풀이: n자리의 1의 자리가 0인 계단수 : n-1자리의 1의 자리수가 0 또는 2인 계단수의 합
// 식으로 표현 1<= L <=8 dp[n][L] = dp[n-1][L-1]+dp[n-1][L+1]
// n의 1의 자리수가 0 일 때는 1 밖에 안됨 : dp[n][0] =dp[n-1][1]
// n의 1의 자리수가 9 일 때는 8 밖에 안됨 : dp[n][9] =dp[n-1][8]
// 이차원 dp 배열에 n 자리의 L로 끝나는 계단 수의 개수 저장
// n=1일 때 0으로 시작하는 수 없으므로 dp[1][0]=0 임
// 주의: dp값이 커서 long long 자료형 써야 됨
// 주의: 출력에 1000000000 으로 나눈 나머지를 출력해야 하는데 dp 과정중에도 1000000000을 나눈 나머지를 저장해야 답 맞음 -> 이해 안감
// 질문: 출력에 1000000000 으로 나눈 나머지를 출력해야 하는데 dp 과정중에도 1000000000을 나눈 나머지를 저장해야 답 맞음 -> 과정중에서 10억보다 큰 수가 나올 수 있음
// 1~9 : 9
// 10 12 21 23 ... 87 89 98 : 17
#define MAX 100001
int n;
long long dp[MAX][11];

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	// 바텀업 dp 구현
	// dp 점화식: 
	// N번째 자리 숫자가 0이면 dp[i][j] = (dp[i - 1][j + 1])
	// N번째 자리 숫자가 1~8까지 : dp[N][i] = dp[N-1][i-1] + dp[N-1][i+1]
	// N번째 자리 숫자가 9 일때 : dp[N][i] = dp[N-1][i-1] 
	// 1째 자리 숫자의 계단수 초기값
	dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1; dp[1][4] = 1; dp[1][5] = 1; dp[1][6] = 1; dp[1][7] = 1; dp[1][8] = 1; dp[1][9] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { dp[i][j] = (dp[i-1][j + 1])% 1000000000; }
			if (j >= 1 && j <= 8) { 
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])% 1000000000;
			}
			if (j == 9) { dp[i][j] = (dp[i - 1][j - 1])% 1000000000; }
		}
	}
	
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	cout << sum % 1000000000 << '\n';
	
	return 0;
}
