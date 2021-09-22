#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 9095 c++ OOOO] 1, 2, 3 더하기
// 문제: 정수를 1,2,3의 합으로 나타내는 방법의 수를 출력
// 접근1: 1,2,3 경우를 나눔 -> dp -> 탑다운 방식: 정수 i 가되는 경우 
// 1. i-1 에서 1 더한 것
// 2. i-2에서  2 더한 것
// 3. i-3 에서 3 더한것 3가지
// 점화식 : dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
// 바텀업 dp 구현
// 시간복잡도: O(n)
// 접근2: 완전탐색-> 재귀 -> 1,2,3, 각각 더할때 모두 탐색
// 시가복잡도: O(3^n) , dp 가 더 빠른 듯
// 풀이1:
// dp로 풀이
// 풀이2:
// 완전탐색 재귀
// n입력,재귀호출
// 현재 합에서 1,2,3더할때 각각 재귀, 합이 n이되면 종료
int t,n,cnt=0;

void re(int sum) { // 현재까지 합,
	if (sum == n) { // 종료조건, 가능한 경우
		cnt++;
		return;
	}
	else if (sum > n) { return; } // 종료조건, 불가능한 경우
	// 1,2,3 더한 경우 재귀
	for (int i = 1; i <= 3; i++) {
		re(sum + i);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		cin >> n;
		re(0);
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}
