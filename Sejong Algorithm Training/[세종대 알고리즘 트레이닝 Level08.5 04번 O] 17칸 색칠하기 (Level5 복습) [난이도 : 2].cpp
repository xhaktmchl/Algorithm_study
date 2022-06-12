#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08.5 04번 O] 17칸 색칠하기 (Level5 복습) [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2, ch3;
char a[20];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2 >> ch3;
	for (int i = 0; i <= 6; i++) {
		a[i] = ch1;
	}
	for (int i = 7; i <= 12; i++) {
		a[i] = ch2;
	}
	for (int i = 13; i < 17; i++) {
		a[i] = ch3;
	}

	for (int i = 16; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
