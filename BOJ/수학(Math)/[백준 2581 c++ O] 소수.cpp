#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2581 c++ O] 소수 
// 문제: 일정 구간 안에 있는 소수들의 합과 최소값 출력
// 접근: 에라토스테네스체로 소수판별 -> 탐색
// 풀이: 
#define MAX 10001
int m, n,sum=0,minN=10001;
bool prime[MAX];
// 에라토스테네스의 체
void eratos() {
	prime[1] = 1;
	for (int i = 2; i * i < MAX; i++) {
		for (int j = i * 2; j < MAX; j+=i) {
			prime[j] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> m >> n;
	eratos(); // 소수판별
	for (int i = m; i <= n; i++) {
		if (prime[i] == 0) {
			minN = min(minN, i); // 최소
			sum += i; // 합
		}
	}
	if (sum == 0) { cout << -1 << '\n';}
	else {
		cout << sum << '\n';
		cout << minN << '\n';
	}
	return 0;
}
