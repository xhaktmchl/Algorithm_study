#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 1699 c++ OO] 제곱수의 합
// 문제: 자연수 N을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수 구하기
// 접근1: 그리디: 큰 수부터 제곱하면서 더해서 최소항의 개수 구하기 -> 시도는 안해봄
// 접근2 : 탑다운 dp: 
// n이 되기위한 합의 경우는
// 1. n = (n-1^2)+1^2 , (n-2^2)+2^2 ... (n-sqrt(n)^2)+sqrt(n)^2 의 경우가 나온다 이를 점화식으로 표현하면
// dp[i] = min(dp[(n-1^2)]+1 , dp[(n-2^2)]+1, ...  dp[(n-sqrt(n)^2)]+1) , 항의 개수가 1개 추가이므로 +1을 해주고 최소값을 비교
// 풀이: 
// dp점화식 을 2중 반복으로 실행하면서 최소항의 개수 갱신
#define MAX 1000001
int n;
vector<long long> dp(MAX,1000001);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	
	// 바텀업 dp 구현
	// 점화식: dp[i] = min(dp[(n-1^2)]+1 , dp[(n-2^2)]+1, ...  dp[(n-sqrt(n)^2)]+1)
	dp[0] = 0; // 계산 시 필요하므로 초기화 해줘야 함
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= sqrt(i); j++) {// 최솟값 비교
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
