#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// [백준 1149 c++ VO] RGB거리
// 문제: 각 집마다 서로다른 규칙을 따른 색의 비용의 최소값을 구하는 문제
// 접근: 탑다운 dp -> n번째 집이 r일때 n-1집은g,b중하나 g일때 n-1집은 r,b중 하나, b일때 n-1집은 r,g중 하나
// 점화식 : dp[j][1] = min(dp[j - 1][2], dp[j - 1][3])+r; // j번째 집이 빨
//dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + g;// j번째 집이 초
//dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + b;// j번째 집이 파
// 풀이: 첫번째 집 비용 입력
// 반복문으로 다음 집부터 빨간색이면 전의 집은 초,파 중 최소비용인 경우의 합 저장
// 처음 집의 색이 빨초파 인 3가지 경우중 최소비용 출력
#define MAX 1001
int n;
long long dp[MAX][4];
long long answer = 0;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
								  
	cin >> n;
	int r, g, b;
	cin >> r >> g >> b;

	// dp점화식
	// 점화식 : dp[j][1] = min(dp[j - 1][2], dp[j - 1][3])+r; // j번째 집이 빨
	//dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + g;// j번째 집이 초
	//dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + b;// j번째 집이 파
	dp[1][1] = r; dp[1][2] = g; dp[1][3] = b;
	for (int j = 2; j <= n; j++) {
		cin >> r >> g >> b; // j번째 집의 r,g,b비용
		dp[j][1] = min(dp[j - 1][2], dp[j - 1][3])+r; // j번째 집이 빨
		dp[j][2] = min(dp[j - 1][1], dp[j - 1][3])+g;// j번째 집이 초
		dp[j][3] = min(dp[j - 1][1], dp[j - 1][2])+b;// j번째 집이 파
	}
	// r,g,b로 끝나는 것중 최소비용 저장
	long long min_cost = 1000001;
	min_cost = min(min(dp[n][1], dp[n][2]), dp[n][3]);
	
	// 결과값 출력
	cout << min_cost;

	return 0;
}
