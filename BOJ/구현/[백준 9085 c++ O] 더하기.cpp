#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 9085 c++ O] 더하기 
// 문제:
// 접근: 
// 풀이: 
int t, n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			sum += num;
		}
		cout << sum << '\n';
	}
	return 0;
}
