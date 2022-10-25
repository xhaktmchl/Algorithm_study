#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 06회차 05번 c++ V] 숙직 선생님
문제: 
접근:
풀이:
	//1.입력
	//2.상향식 dp[i] = min(dp[n-a],dp[n-b],dp[n-c])+1
	//3.출력

시간복잡도: O()=
개념:
*/
int a, b, d1, d2, d3;
long long dp[1010];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a >> b;
	cin >> d1 >> d2 >> d3;
	//2.상향식 dp[i] = min(dp[n-d1],dp[n-d2],dp[n-d3])+1
	// do[i] = i까지 오는데 최소 이동 횟수
	fill_n(dp, 1000, 1010);
	dp[1] = 0;
	dp[d1] = 1;
	dp[d2] = 1;
	dp[d3] = 1;
	for (int i = 2; i <= 100; i++) {
		if (i - d1 >= 1 && dp[i - d1] != 1010) { dp[i] = min(dp[i], dp[i - d1])+1; }
		if (i - d2 >= 1 && dp[i - d2] != 1010) { dp[i] = min(dp[i], dp[i - d2])+1; }
		if (i - d3 >= 1 && dp[i - d3] != 1010) { dp[i] = min(dp[i], dp[i - d3])+1; }
	}
	//3.출력
	if (dp[b - a + 1] == 1010) { cout << -1 << '\n'; }
	else { cout << dp[b-a+1] << '\n'; }
	return 0;
}
