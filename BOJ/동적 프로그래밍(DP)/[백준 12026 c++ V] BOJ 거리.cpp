#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
[백준 12026 c++ V] BOJ 거리 
문제: 1부터 N 까지 번호가 있는 블록에서 BOJ순으로 탐색할 때 에너지의 최소양을 구하라. 이동칸 k면 에너지=k*k
접근: 완전탐색 재귀-> BOJ 순으로 갈 수 있는 곳만 재귀 탐색 -> 시간복잡도O(n!) = 1000! 시간초과 예상 
접근2: dp 1차원->
dp점화식 ,
dp[i] = i번째에 오는데 필요한 에너지의 최솟값 , 올 수 있는 모든 이전 블록 중 에너지 최솟값 
dp[i] = min(dp[i-1]+1*1 , dp[i-2]+2*2,... dp[1]+(i-1)*(i-1))
시간복잡도: O(n*n) = 1000*1000 =100만 
풀이:
1.블록갯수, 블록 문자열로 입력
2.최소값 구하기 -> dp배열 최대값으로 초기화
3.바텀업 dp 구현
초기값 시작 1 은 에너지 0
dp[i]는 그 전에 dp[]+이동거리제곱 중 최소값 , BOJ순서조건 만족시만
4.최솟값 출력
*/
#define MAX 1001
int n;
string block; // 블로 문자열
long long dp[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> block;
	
	fill_n(dp, n+1 , 1000000); 
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if ((block[i-1] == 'B' && block[i-1 - j] == 'J') || (block[i-1] == 'O' && block[i-1 - j] == 'B') || (block[i-1] == 'J' && block[i-1 - j] == 'O')) {
				dp[i] = min(dp[i], dp[i - j] + j * j);
			}
		}
	}
	if (dp[n] == 1000000) { cout << -1 << '\n'; }
	else { cout << dp[n] << '\n'; }
	return 0;
}
