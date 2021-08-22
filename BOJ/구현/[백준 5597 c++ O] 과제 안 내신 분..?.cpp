#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5597 c++ O] 과제 안 내신 분..?
// 문제:
// 접근: 
// 풀이: 
#define MAX 31
bool ch[MAX];
int n;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 28; i++) {
		cin >> n;
		ch[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (ch[i] == 0) { cout << i << '\n'; }
	}
	return 0;
}
