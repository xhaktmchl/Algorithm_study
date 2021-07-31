#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1929 c++ V] 소수 구하기
// 문제: n개의 수중 소수의 갯수 구하기
// 접근1: 완전탐색 1~n-1 까지 -> 시간초과 예상
// 접근2: 2~루트n 까지 -> 시도 안 해봄
// 루트n 은 i*i<n 이렇게 구현
// 접근3: 에라토스테네스-> 배열에 미리 소수판별 -> 입력받는 숫자 소수판별
// 똑같이 루트n 은 i*i<n 이렇게 구현
// 시간복잡도:
// 풀이: 
// 숫자 입력
// 에라토스테네스 체로 배열에 소수 표시
// 정해진 구간의 소수들 출력
// 주의:
//: 에라토스테네스의 체도 루트n까지 탐색하면 됨
#define MAX 1000001
int m, n;
int prime[MAX];

// 에라토스 테ㅅ네스 체
void eratos() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i*i < MAX; i++) {
		for (int j = 2*i; j <= MAX; j += i) {
			if (prime[j] == 0) { prime[j] = 1; }
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> m >> n;

	eratos();
	// 소수 출력
	int c = 0;
	for (int i = m; i <= n; i++) {
		if (prime[i] == 0) { cout << i << '\n'; }
	}
	
	return 0;
}
