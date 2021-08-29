#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2711 c++ O] 오타맨 고창영 
// 문제: 
// 접근: 문자열 제거 erase 내장 함수 이용 
// 시간복잡도: O(t*s) = 1000*80 
// 풀이: 
int t,idx;
string s;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> idx >> s;
		s.erase(s.begin() + idx - 1);
		cout << s << '\n';
	}
	return 0;
}
