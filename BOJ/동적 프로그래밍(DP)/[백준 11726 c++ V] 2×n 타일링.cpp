#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 11726 c++ V] 2×n 타일링
// 문제: 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수 구하기
// 접근: n=1부터 차례로 방법의 수들 구해보기 -> 규칙(전화식 찾기)
// 접근2 : dp라 생각하고 탑다운 방식으로 n번째에 더해지는 경우들을 생각 -> 
//n번째에는 n-1번째에서  2×1 하나 추가하는 방법과
// n-2번째에서 1x2 두 개 추가하는 방법 존재
// 점화식:dp : dp[i] = dp[i-1]+dp[i-2]
// 풀이: 
// 주의:
// 숫자가 커서 10007로 나누면서 저장

#define MAX 1001
long long n;
vector<int> dp(MAX);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> n;
	// 점화식
	// dp : dp[i] = dp[i-1]+dp[i-2]
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; 
	}
	cout << dp[n] << '\n';
	return 0;
}
