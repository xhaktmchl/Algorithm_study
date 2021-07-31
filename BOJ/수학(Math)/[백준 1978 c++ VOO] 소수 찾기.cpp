#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1978 c++ VOO] 소수 찾기
// 문제: n개의 수중 소수의 갯수 구하기
// 접근1: 완전탐색 1~n-1 까지
// 접근2: 2~루트n 까지
// 루트n 은 i*i<n 이렇게 구현
// 접근3: 에라토스테네스-> 배열에 미리 소수판별 -> 입력받는 숫자 소수판별
// 세가지 모두 가능
// 풀이: 
// 루트n 이용
// n개의 수 입력받으며 소수이면 갯수 증가
int n,c=0;

bool isPrime(int num) {
	if (num < 2) { return false; }
	else {
		for (int i = 2; i * i <= num; i++) { // 루트n 은 i*i<n 이렇게 구현
			if (num % i == 0) { return false; }
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (isPrime(num)) { c++; }
	}

	cout << c << '\n';

	return 0;
}
