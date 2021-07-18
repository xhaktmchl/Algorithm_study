#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 16194 c++ O] 카드 구매하기 2
// 문제: n 개의 카드를 구매할 때 비용의 최솟값 구하기
// 접근1: 완전텀색 -> 시간초과 예상
// 접근2: 그리디: 제일 작은 값만 더하기 또는 가성비 제일 좋은카드만 더하기 ->카드갯수의 합이 n개가 되는지 모름
// 접근3: n가지 경우들의 합 최소 -> dp -> 탑다운: 
//카드 n개를 살 때의 최솟값은
//카드 n - 1개를 살 때의 최솟값 + 1번째 카드
//카드 n - 2개를 살 때의 최솟값 + 2번째 카드 ...계속
//카드 0개를 살 때의 최솟값 + n번째 카드 중 최솟값 .
// 결국 n 개를 살 때 카드의 합이 n이되는 조합들 중 최솟값을 dp 에 저장하고
// dp[0] 부터 차례로 저장해나가야 함
// dp[i] = max((dp[i-1]+ar[1]),(dp[i-2]+ar[2]),... ,(dp[i-i]+ar[i]))
// 풀이: 
// 주의: n번째 dp는 카들 조합들중 최솟값이므로 이중 반복문이어야 함
// : 최솟값을 구하므로 dp배열 최대숫자로 초기화 해줘야 함
#define MAX 1001
int n;
vector<int> dp(MAX,10001); // 최솟값을 구해야 하므로 최대 숫자로 초기화
vector<int> ar(MAX);
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> n;
	// 카트의 값 입력
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	// dp 점화식
	// dp[i] = max((dp[i-1]+ar[1]),(dp[i-2]+ar[2]),... ,(dp[i-i]+ar[i]))
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + ar[j]);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
