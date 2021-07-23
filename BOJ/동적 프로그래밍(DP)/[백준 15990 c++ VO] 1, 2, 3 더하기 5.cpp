#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 15990 c++ VO] 1, 2, 3 더하기 5 
// 문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력, 같은 숫자 연속된 수의 합은 안됨
// 접근: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우 
// 2차원 dp 로 1,2,3으로 끝나는 방법의 수 각자 저장
// 1.i 에서  1 이 마지막에 더할려면 i-1에서 2또는 3으로 끝난 방법들을 더함
// 2.i-2 에서  2 이 마지막에 더할려면 i-1에서 2또는 3으로 끝난 방법들을 더함
// 3.  3가지i-3 에서  3 이 마지막에 더할려면 i-1에서 2또는 3으로 끝난 방법들을 더함
// 점화식 : 
//dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]); // 마지막이 1 인경우 전의 숫자는 2또는 3
//dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]);// 마지막이 2 인경우 전의 숫자는 1또는 3
//dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]);// 마지막이 3 인경우 전의 숫자는 1또는 2
// 바텀업으로 구현
// 시간복잡도: O(n)
// 풀이: 
// 점화식 배열 만들고
// 숫자 입력받아 합의 방법 출력
// 주의:
//: 숫자가 커서 출력 long long으로 해야 함
#define MAX 100001
int n,t;
long long dp[MAX][4];

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 바텀업 dp 구현
	// dp점화식 
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009; // 마지막이 1 인경우 전의 숫자는 2또는 3
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;// 마지막이 2 인경우 전의 숫자는 1또는 3
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;// 마지막이 3 인경우 전의 숫자는 1또는 2
	}
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		long long sum = (dp[n][1] + dp[n][2] + dp[n][3])% 1000000009;
		cout << sum << '\n';
	}
	
	
	return 0;
}
