#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 9095 c++ O] 1, 2, 3 더하기
// 문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
// 접근: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우 
// 1.i-1 에서 1 더한 것
// 2. i-2에서  2 더한 것
// 3. i-3 에서 3 더한것 3가지
// 점화식 : dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
// 풀이: 

#define MAX 12
int n;
vector<int> dp(MAX);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> n;
	// dp 점화식
	// dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	// 숫자 입력받고 정답 출력
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << dp[num]<<'\n';
	}
	return 0;
}
