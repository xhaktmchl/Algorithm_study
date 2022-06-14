#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 10번 O] 문장을 입력받고 길이 구하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

void CountLine(char a[3][10]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] == 0) {
				cout << j << "=";
				for (int p = 0; p < j; p++) {
					cout << a[i][p];
				}cout << '\n';
				break;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char a[3][10] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}

	CountLine(a);
	return 0;
}
