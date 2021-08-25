#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [백준 20001 c++ O] 고무오리 디버깅
// 문제:
// 접근: 기본 스택 문제
// 시간복잡도: 
// 풀이1:  
// 개념:
string s;
stack<int> st;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	while (1) {
		getline(cin, s);
		if (s == "고무오리 디버깅 시작") { continue; }
		if (s == "문제") {
			st.push(1);
		}
		else if (s == "고무오리") {
			if (st.empty()) { st.push(1); st.push(1); }
			else { st.pop(); }
		}
		else if (s == "고무오리 디버깅 끝") {
			if (st.empty()) { cout << "고무오리야 사랑해" << '\n'; }
			else { cout << "힝구" << '\n'; }
			break;
		}
	}
    return 0;
}
