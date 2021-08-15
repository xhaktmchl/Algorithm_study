#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5598 c++ O] 카이사르 암호
// 문제: 
// 접근: 기본 구현
// 시간복잡도: 
// 풀이: 
string s;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] = 'A' + (26 + (s[i] - 'A') - 3) % 26;
	}
	cout << s << '\n';
	return 0;
}



