#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10820 c++ O] 문자열 분석
// 문제: 문자열 입력받고 소문자, 대문자, 숫자, 공백 갯수 출력
// 접근: getline 으로 입력하고 완전탐색
// 시간복잡도: O(n*t)
// 풀이: 
int c1, c2, c3, c4; 
string s;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	while (1) {
		c1 = 0; c2 = 0; c3 = 0; c4 = 0;
		getline(cin, s); // 문자열 공백포함 입력
		if (s == "") { break; }
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') { c1++; }
			if (s[i] >= 'A' && s[i] <= 'Z') { c2++; }
			if (s[i] >= '0' && s[i] <= '9') { c3++; }
			if (s[i] == ' ') { c4++; }
		}
		cout << c1 <<" "<< c2<<" " << c3 <<" "<< c4 << '\n';
	}
	return 0;
}


