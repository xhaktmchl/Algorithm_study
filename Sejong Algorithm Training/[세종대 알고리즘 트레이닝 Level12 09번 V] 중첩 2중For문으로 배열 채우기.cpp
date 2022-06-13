#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 09번 V] 중첩 2중For문으로 배열 채우기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
int a[5][5];
int n = 1;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	if (ch >= '0' && ch <= '9') {
		for (int i = 2; i >= 0; i--) {
			for (int j = 2; j >= i; j--) {
				a[i][j] = n++;
			}
		}
	}
	else if (ch >= 'A' && ch <= 'Z') {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				a[i][j] = n++;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 0) { cout << " "; }
			else {
				cout << a[i][j];
			}
		}cout << '\n';
	}
	return 0;
}
