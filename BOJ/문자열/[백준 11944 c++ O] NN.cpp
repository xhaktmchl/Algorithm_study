#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11944 c++ O] NN 
// 문제: 
// 접근1: 
// 시간복잡도: 
// 풀이: 
int n,m;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> m;
	string s = to_string(n);
	string ans;
	while (n--) {
		ans += s;
		if (ans.size() > m) { break; }
	}
	cout << ans.substr(0,m) << '\n';
	return 0;
}
