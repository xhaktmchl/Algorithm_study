#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 9325 c++ O] 얼마?
// 문제:
// 접근: 기본 수학
// 풀이: 
int s, n,t,q,p;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		long long sum = 0;
		cin >> s >> n;
		sum += s;
		for (int i = 0; i < n; i++) {
			cin >> q >> p;
			sum += q * p;
		}
		cout << sum << '\n';
	}
	return 0;
}
