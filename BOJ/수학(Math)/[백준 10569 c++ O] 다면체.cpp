#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10569 c++ O] 다면체 
// 문제:
// 접근: 기본 수학
// 풀이: 
int t,v,e;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		cout << 2 - v + e << '\n';
	}
	return 0;
}
