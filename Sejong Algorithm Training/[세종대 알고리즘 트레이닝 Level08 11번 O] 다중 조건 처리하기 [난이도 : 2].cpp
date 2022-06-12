#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08 11번 O] 다중 조건 처리하기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

void starBox() {
	for (int i = 1; i <= 20; i++) {
		if (i % 2 == 1) { cout << i << " "; }
	}
}

void macDoll() {
	for (char i = 'H'; i >= 'A'; i--) {
		cout << i<<" ";
	}
}

void copyBean() {
	for (int i = -5; i <= 5; i++) {
		cout << i << " ";
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if (n >= 3500 && n <= 5000) {
		starBox();
	}
	else if (n >= 2500) {
		macDoll();
	}
	else {
		copyBean();
	}
	return 0;
}
