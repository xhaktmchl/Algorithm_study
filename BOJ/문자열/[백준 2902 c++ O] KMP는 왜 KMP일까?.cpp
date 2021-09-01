#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2902 c++ O] KMP는 왜 KMP일까? 
// 문제: 
// 접근: 
// 시간복잡도: O(문자열 길이)
// 풀이: 
string s;
vector<char> a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) { a.push_back(s[i]); continue; }
		if (s[i] == '-') { a.push_back(s[i+1]); continue; }
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}cout << '\n';
	return 0;
}
