#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2744 c++ O] 대소문자 바꾸기
// 문제:
// 접근:
// 시간복잡도: 
// 풀이1:  인덱스 직접 구현
// 풀이2: toupper(), tolower() 함수 이용 
// 개념:
// toupper() tolower(), 헤더#include <string>
string s;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') { s[i] = toupper(s[i]); }
		else if (s[i] >= 'A' && s[i] <= 'Z') { s[i] = tolower(s[i]); }
	}
	cout << s << '\n';
    return 0;
}
