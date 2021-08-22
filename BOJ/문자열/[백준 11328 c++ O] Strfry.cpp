#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11328 c++ O] Strfry 
// 문제:
// 접근: 애너그램 -> 결국 공통된 문자의 갯수 같으면 애너그램 가능
// 풀이: 
// 각 문자열의 알파벳의 갯수 저장
// 문자의 갯수가 맞지 않으면 불가능/ 맞으면 가능
#define MAX 30
int n;
string a, b;
int cnta[MAX], cntb[MAX];
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		cin >> a >> b;
		memset(cnta, 0, sizeof(cnta));
		memset(cntb, 0, sizeof(cntb));
		bool ok = 1;
		for (int i = 0; i < a.size(); i++) {
			cnta[a[i] - 'a']++;
		}
		for (int i = 0; i < b.size(); i++) {
			cntb[b[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnta[i] != cntb[i]) { ok = false; break; }
		}
		if(ok){ cout << "Possible" << '\n'; }
		else { cout << "Impossible" << '\n'; }
	}
	return 0;
}
