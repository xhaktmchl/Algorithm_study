#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 10번 O] 한줄로 문자 채우기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int row;
char ch;
char a[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> row >> ch;
	for (int i = 4; i >= 0; i--) {
		a[row - 1][i] = ch;
		ch++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == '\0') { cout << "0"; }
			else { cout << a[i][j]; }
		}cout << '\n';
	}
	return 0;
}
