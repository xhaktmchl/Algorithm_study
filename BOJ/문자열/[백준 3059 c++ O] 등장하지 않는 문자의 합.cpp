#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 3059 c++ O] 등장하지 않는 문자의 합
// 문제:
// 접근:
// 시간복잡도: 
// 풀이1:  
// 개념:
#define MAX 26
int t;
string s;
int ch[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		memset(ch, 0, sizeof(ch));
		cin >> s;
		for (int i = 0; i < s.size(); i++) { // 존재하는 알파벳 체크
			ch[s[i] - 'A'] = 1;
		}
		int sum = 0;
		for (int i = 0; i < 26; i++) { // 등장하지 않은 알파벳 아스키코드 합 구하기
			if (ch[i] == 0) {
				sum += (int)('A' + i);
			}
		}cout << sum << '\n';
	}

    return 0;
}
