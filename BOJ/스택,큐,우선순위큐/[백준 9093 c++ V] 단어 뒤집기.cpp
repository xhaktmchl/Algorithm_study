#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 9093 c++ V] 단어 뒤집기
// 문제: 문장이 주어졌을 때,단어의 순서는 바꾸지 않고 단어를 모두 뒤집어서 출력
// 접 각 단어마다 역순 -> 스택 
// 풀이: 
// 문장  공백포함 입력
// 입력받은 문장 완전탐색하며 스택에 푸쉬
// 공백나올 때 마다 스택에 있는 모든 문자 pop해서 역순 출력
// 주의:
// : 문장 입력할 때 str += ' '; 마지막에 공백을 더해야 문자열 탐색할 때 마지막 문자도 탐색할 수 있음
int t;
string str;
stack<char> st;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
								  
	cin >> t;
	cin.ignore(); // getchar() 와 같은 기능
	for (int i = 0; i < t; i++) {
		getline(cin, str); // 공백포함 입력
		str += ' '; //마지막에 공백을 더해야 문자열 탐색할 때 마지막 문자도 탐색할 수 있음
		//  
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {// 공백나올 때 마다 스택에 있는 모든 문자 pop해서 역순 출력
				while (!st.empty()) {
					cout<<st.top();
					st.pop();
				}
				cout << ' ';
			}
			else {// 입력받은 문장 완전탐색하며 스택에 푸쉬
				st.push(str[j]);
			}
		}
		cout << '\n';
	}
	
	return 0;
}
