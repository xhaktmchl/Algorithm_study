#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2501 c++ O] 약수 구하기
// 문제:
// 접근: 
// 풀이: 
int n, k;
vector<int> a;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) { a.push_back(i); }
	}
	if (k > a.size()) { cout << 0 << '\n'; }
	else { cout << a[k - 1] << '\n'; }
	return 0;
}
