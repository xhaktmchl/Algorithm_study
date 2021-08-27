#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
#include <queue>
using namespace std;
// [백준 1935 c++ V] 후위 표기식2
// 문제:
// 접근: 후위표기식 계산 -> 스택 , cout으로 소수점 고정하는것을 몰랐음
// 시간복잡도: 
// 풀이:  
// 알파벳이면 해당 숫자 스택에 푸쉬
// 연산자면 스택에서 숫자 2개 팝해서 계산 후 스택에 푸쉬
// 개념: 
// cout<<fixed; cout<<precision(2); 소수점 2째자리까지 반올림 고정
#define MAX 27
stack<double> st;
int n;
double num[MAX];
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { // 알파벳이면 숫자 대입
			int idx = s[i] - 'A';
			st.push(num[idx]);
		}
		else if (s[i] == '+') { // 덧셈
			double n1 = st.top(); st.pop();
			double n2 = st.top(); st.pop();
			st.push(n2 + n1);
		}
		else if (s[i] == '-') { // 뺄셈
			double n1 = st.top(); st.pop();
			double n2 = st.top(); st.pop();
			st.push(n2 - n1);
		}
		else if (s[i] == '*') { // 곱셈
			double n1 = st.top(); st.pop();
			double n2 = st.top(); st.pop();
			st.push(n2 * n1);
		}
		else if (s[i] == '/') { // 나눗셈
			double n1 = st.top(); st.pop();
			double n2 = st.top(); st.pop();
			st.push(n2 / n1);
		}
	}
	cout << fixed; // 소수점 2째 자리까지 반올림
	cout.precision(2);
	cout << st.top() << '\n'; 
    return 0;
}
