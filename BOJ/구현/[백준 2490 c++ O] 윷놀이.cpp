#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2490 c++ O] 윷놀이 
// 문제:
// 접근: 
// 풀이: 
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		int c = 0;
		for (int j = 0; j < 4; j++) {
			int n; cin >> n;
			if(n==0) c++;
		}
		if (c == 0) { cout << 'E' << '\n'; }
		else {	cout << (char)('A' + c - 1) << '\n';}
	}
	return 0;
}
