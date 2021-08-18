#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2748 c++ O] 피보나치 수 2  
// 문제: 
// 접근: 피보나치 -> dp
// 풀이: 
// 범위가 크기 때문에 longlong 으로 해야 함
#define MAX 92
int n;
long long dp[MAX];
int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n+1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n+1] << '\n';
	return 0;
}
