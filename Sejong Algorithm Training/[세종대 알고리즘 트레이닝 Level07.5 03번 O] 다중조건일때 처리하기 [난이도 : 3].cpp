#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07.5 03번 O] 다중조건일때 처리하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10];
int cnt = 0;

void input() {
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
		if (a[i] >= 'A' && a[i] <= 'Z') { cnt++; }
	}
}

void output() {
	if (cnt == 2) { cout << "대문자들"; }
	else if (cnt == 1) { cout << "대소문자"; }
	else {
		for (char i = 'a'; i <= 'z'; i++) {
			cout << i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	input();
	output();
	return 0;
}
