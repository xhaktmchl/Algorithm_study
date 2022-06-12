#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 12번 O] 복잡한 조건에 맞게 출력하기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

void BBQ() {
	if (n > 0 && n < 5) {
		cout << "초기값";
	}
	else if (n > 6 && n < 10) { cout << "중간값"; }
	else { cout << "알수없는값"; }
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		for (int i = 1; i <= 10; i++) {
			cout << i;
		}cout << '\n';
	}
	else if (n == 0 || n == 8) {
		for (int i = 10; i >= 1; i--) {
			cout << i;
		}cout << '\n';
	}
	else {
		BBQ();
	}
    return 0;
}
