#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 05번 O] 중첩 for문 활용하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[5][5];


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 2 - i; j < 4; j++) {
			a[i][j] = n++;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] != 0) {
				cout << a[i][j];
			}
			else { cout << " "; }
		}cout << '\n';
	}
	return 0;
}
