#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1919 c++ O] 애너그램 만들기
// 문제:
// 접근: 애너그램 -> 결국 같은 공통된 문자의 갯수가 같은 것 제외는 버림
// 풀이: 
// 각 문자의 갯수 저장 후 공통되지 않는 문자 갯수 합 구하기
#define MAX 30
string a, b;
int cnta[MAX], cntb[MAX];
int sum = 0;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> a >> b;
	// 각 문자의 갯수 저장
	for (int i = 0; i < a.size(); i++) {
		cnta[a[i] - 'a'] += 1;
	}
	for (int i = 0; i < b.size(); i++) {
		cntb[b[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		sum += abs(cnta[i] - cntb[i]); // 공통된 문자 말고 지우기
	}
	cout << sum << '\n';
	return 0;
}
