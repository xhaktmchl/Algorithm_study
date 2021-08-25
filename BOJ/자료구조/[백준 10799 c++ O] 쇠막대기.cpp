#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
using namespace std;
// [백준 10799 c++ O] 쇠막대기
// 문제:
// 접근: 스택
// 시간복잡도: 
// 풀이1:  
// 개념:
string s;
stack<char> st;
int sum = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push('(');
			if (s[i + 1] != ')') { sum++; } // 처음 쇠막대 개수
		}
		else if (s[i] == ')') {
			st.pop();
			if(s[i-1] == '(' && !st.empty()){ // 쇠막대 잘릴 때 개수 걸쳐진 쇠막대 개수만큼 증가
				sum += st.size();
			}
		}
	}
	cout << sum << '\n';
    return 0;
}
