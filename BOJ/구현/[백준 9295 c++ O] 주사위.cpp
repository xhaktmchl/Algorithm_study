#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 9295 c++ O] 주사위 
// 문제:
// 접근: 
// 풀이: 
int t,c=1;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << "Case " << c << ": " << n1 + n2 << '\n';
		c++;
	}
	return 0;
}
