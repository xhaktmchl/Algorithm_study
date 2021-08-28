#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [알고스팟 19.4 c++ O] 짝이 맞지 않는 괄호
// 문제:
// 접근: 괄호 짝 맞추기 -> 전형적인 스택
// 시간복잡도: O(n*s) = 100*10000 = 100만
// 풀이: 
// 열린 괄호면 스택에 푸쉬
// 닫히는 괄호 인 경우 예외:스택이 없거나 , 열린괄호가 짝 아니면 에러 , 나머진 옳음
// 예외: 탐색이 다 끝나고 스택 남아있으면 에러
// 다 통과하면 올바른 괄호
int n;
string s;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		cin >> s;
		stack<int> st;
		bool ok = 1;
		for (int i = 0; i < s.size(); i++) {
			// 닫는 괄호면
			if (s[i] == ')') { // ) 괄호 시
				if (st.empty()) { ok = false; }
				else if (st.top() != '(') { ok = false; }
				else {	st.pop();}
			}
			else if (s[i] == '}') {// } 괄호 시
				if (st.empty()) { ok = false; }
				else if (st.top() != '{') { ok = false; }
				else {st.pop();}
			}
			else if (s[i] == ']') {//] 괄호 시
				if (st.empty()) { ok = false; }
				else if (st.top() != '[') { ok = false; }
				else {	st.pop();}
			}
			// 여는 괄호면
			else {	st.push(s[i]); 	} // ({[ 는 스택에 푸쉬
		}
		if (!st.empty()) { ok = false; } //예외처리 끝나고 스택에 남아도 틀림
		if (ok) { cout << "YES" << '\n'; }
		else { cout << "NO" << '\n'; }
	}
    return 0;
}
