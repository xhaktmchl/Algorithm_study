#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 1149 c++ VOO] RGB거리
// 문제: 각 집마다 서로다른 규칙을 따른 색의 비용의 최소값을 구하는 문제
// 접근: 탑다운 dp -> n번째 집이 r일때 n-1집은g,b중하나 g일때 n-1집은 r,b중 하나, b일때 n-1집은 r,g중 하나
// 점화식 : dp[i][j]: i번 까지의 집을 j 번 색으로 칠하는 비용의 최소값
//dp[j][1] = min(dp[j - 1][2], dp[j - 1][3])+r; // j번째 집이 빨
//dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + g;// j번째 집이 초
//dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + b;// j번째 집이 파
// 시간 복잡도:O(n)
// 풀이: 첫번째 집 비용 입력
// 반복문으로 다음 집부터 빨간색이면 전의 집은 초,파 중 최소비용인 경우의 합 저장
// 처음 집의 색이 빨초파 인 3가지 경우중 최소비용 출력
#define MAX 1001
int n,r,g,b;
int dp[MAX][3];

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 바텀업 dp 구현
	// dp점화식
	// 점화식 : dp[j][1] = min(dp[j - 1][2], dp[j - 1][3])+r; // j번째 집이 빨
	//dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + g;// j번째 집이 초
	//dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + b;// j번째 집이 파
	cin >> n;
	cin >> r >> g >> b;
	dp[1][0] = r;
	dp[1][1] = g;
	dp[1][2] = b;
	for (int i = 2; i <= n; i++) {
		cin>>r>>g>>b; // j번째 집의 r,g,b비용
		dp[i][0] = min(dp[i - 1][1],dp[i - 1][2])+r; // i번째 집이 빨
		dp[i][1] = min(dp[i - 1][0],dp[i - 1][2])+g; // i번째 집이 초
		dp[i][2] = min(dp[i - 1][0],dp[i - 1][1])+b; // i번째 집이 파
	}
	// 빨,초,파 중 최소비용 출력
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
	return 0;
}
