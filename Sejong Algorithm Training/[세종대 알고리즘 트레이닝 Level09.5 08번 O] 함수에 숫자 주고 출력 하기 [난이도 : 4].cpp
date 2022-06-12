#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 08번 O] 함수에 숫자 주고 출력 하기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

void BBQ(int num) {
	for (int i = 1; i <= num; i++) {
		cout << i;
	}
}

void KFC(char tar) {
	for (int i = 0; i < 7; i++) {
		cout << tar;
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;

	if (n % 2 == 1) {
		int tp;
		cin >> tp;
		BBQ(tp);
	}
	else {
		char ch;
		cin >> ch;
		KFC(ch);
	}
	return 0;
}
