#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [백준 3986 c++ O] 좋은 단어
// 문제:
// 접근: 스택으로 접근하기가 어려울 것 같음
// 시간복잡도: O(1000000)
// 풀이1:  
// 같은 문자가 오면 스택에서 제거 -> 마지막 스택에 문자 없어야 좋은 단어
int n,c=0;
string s;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		stack<char> st;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (st.empty()) { st.push(s[i]); } // 스택 비면 푸쉬
			else {
				if (s[i] == st.top()) {	st.pop();} // 마지막 문자와 같으면 팝
				else { st.push(s[i]);} // 다르면 푸쉬
			}
		}
		// 좋은단어 판별
		if (!st.empty()) { continue; }
		else { c++; }
	}
	cout << c << '\n';
    return 0;
}
