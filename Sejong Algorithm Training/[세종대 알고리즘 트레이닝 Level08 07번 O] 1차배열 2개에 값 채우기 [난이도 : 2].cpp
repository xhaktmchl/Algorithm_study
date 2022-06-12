#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08 07번 O] 1차배열 2개에 값 채우기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10] = "BD5QA";
char b[10] = "QEREF";
char ch;

void input() {
	cin >> ch;
}

void output() {
	if (ch >= 'a' && ch <= 'z') {
		for (int i = 0; i < 5; i++) {
			cout << a[i];
		}
	}
	else if (ch >= 'A' && ch <= 'Z') {
		for (int i = 0; i < 5; i++) {
			cout << b[i];
		}
	}
	else {
		cout << "HGFEDCBA";
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	input();
	output();
	return 0;
}
