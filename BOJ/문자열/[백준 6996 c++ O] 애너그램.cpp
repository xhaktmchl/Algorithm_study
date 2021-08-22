#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 6996 c++ O] 애너그램 
// 문제:
// 접근1: 애너그램 -> 각 알파벳의 갯수가 같으면 애너그램
// 접근2: 애너그램 -> 두 문자열 정렬해서 같으면 애너그램
// 시간복잡도: 접근1 < 접근2
// 풀이: 접근1
#define MAX 31
int n;
string a, b;
int cnta[MAX], cntb[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		bool ok = 1;
		memset(cnta, 0, sizeof(cnta));
		memset(cntb, 0, sizeof(cntb));
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++) { // 문자열 의 알파벳 갯수
			cnta[a[i] - 'a']++;
		}
		for (int i = 0; i < b.size(); i++) {// 문자열 의 알파벳 갯수
			cntb[b[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) { // 알파벳 갯수 같은지 검사
			if (cnta[i] != cntb[i]) { ok = false; }
		}
		if (ok) { cout << a << " & " << b << " are anagrams." << '\n'; }
		else { cout << a << " & " << b << " are NOT anagrams." << '\n'; }
	}
	return 0;
}
