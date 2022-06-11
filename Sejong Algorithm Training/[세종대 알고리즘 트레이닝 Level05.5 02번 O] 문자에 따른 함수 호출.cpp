#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level05.5 02번 O] 문자에 따른 함수 호출
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char op;

void KFC() {
	cout << "KFC" << '\n';
}

void BBQ() {
	cout << "BBQ" << '\n';
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> op;
	if (op == 'B') {
		KFC();
		BBQ();
	}
	else if (op == 'b') {
		BBQ();
	}
	else if (op == '7') {
		KFC();
	}
    return 0;
}
