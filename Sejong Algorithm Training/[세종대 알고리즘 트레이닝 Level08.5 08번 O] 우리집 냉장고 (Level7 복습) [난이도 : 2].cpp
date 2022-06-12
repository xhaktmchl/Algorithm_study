#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08.5 08번 O] 우리집 냉장고 (Level7 복습) [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n1, n2;
int a[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n1 >> n2;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = n1;
		}
	}
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = n2;
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}cout << '\n';
	}
	return 0;
}
