#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [백준 4889 c++ V] 안정적인 문자열
// 문제:
// 접근: 괄호? -> 스택 큐 
// 시간복잡도: 
// 풀이1:  
// 짝수개라 멀쩡한 것 지우고 남는 것 {{,}},}{
// {{,}} 은 바꾸는 횟수 1 증가
// }{ 는 바꾸는 횟수 2 증가
string s;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	while (1) {
		cnt++;
		cin >> s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{') { st.push(s[i]); } // {
			else if (s[i] == '}'){ // }
				if(st.empty() || st.top() == '}'){ st.push(s[i]); } // st.empty() 먼저 검사해야 함
				else { st.pop(); }
			}
			else { // 중단
				return 0;
			}
		}

		// 바꾸는 횟수
		int c = 0;
		while (!st.empty()) {
			char tp = st.top();
			st.pop();
			if (tp == st.top()) { c += 1; } // {{ , }}
			else { c += 2; } // }{ 
			st.pop(); 
		}
		cout <<cnt<<". "<< c << '\n';
	}
    return 0;
}
