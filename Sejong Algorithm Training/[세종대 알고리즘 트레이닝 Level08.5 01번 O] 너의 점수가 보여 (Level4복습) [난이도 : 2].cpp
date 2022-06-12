#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08.5 01번 O] 너의 점수가 보여 (Level4복습) [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 6; i++) {
		if (a[i] >= 5) { cout << i << "번은 " << a[i] << "점 합격" << '\n'; }
		else{ cout << i << "번은 " << a[i] << "점 불합격" << '\n'; }
	}
	return 0;
}
