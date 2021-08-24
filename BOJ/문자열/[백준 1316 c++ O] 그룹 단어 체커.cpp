#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1316 c++ O] 그룹 단어 체커
// 문제:
// 접근:
// 시간복잡도: 
// 풀이1:  
// 개념:
#define MAX 26
int n,c=0;
string s;
int ch[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		cin >> s;
		bool ok = 1;
		memset(ch, 0, sizeof(ch));
		for (int i = 0; i < s.size(); i++) {
			if (ch[s[i]-'a'] == 0) { ch[s[i]-'a'] = 1; }
			else {
				if (s[i-1] != s[i]) { ok = false; }
			}
		}
		if (ok) { c++; }
	}
	cout << c << '\n';
    return 0;
}
