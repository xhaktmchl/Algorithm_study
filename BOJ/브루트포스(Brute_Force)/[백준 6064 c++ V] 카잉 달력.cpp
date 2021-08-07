#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 6064 c++ V] 카잉 달력
// 문제: 카잉 달력에 원하는 날짜는 몇 번째 해인지 구하라
// 접근1: 완전탐색 -> 시간초과
// 시간복잡도: O(n*m) = 16억
// 접근2: 건너뛰며 완전탐색 -> 인덱스를 x의 주기만큼 더하며 탐색하면 x는 고정, y만 탐색 하는 것
// 시간복잡도: O(n) = 4만
// 풀이: 
// x,y -1 해주면 나머지 연산으로 순환가능
// x의 주기만큰 인덱스 이동하며 y가 같은지 검사
int t, m, n,x,y;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		int c = 0;
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;
		// 건너뛰며 완전탐색
		for (int i = x; i < n * m; i += m) { // 주기m만큼 이동해서 x가 같은 것만 탐색
			if (i % n == y) { cout << i+1 << '\n'; c++; break; }
		}
		if (c == 0) { cout << -1 << '\n'; }
	}
	return 0;
}



