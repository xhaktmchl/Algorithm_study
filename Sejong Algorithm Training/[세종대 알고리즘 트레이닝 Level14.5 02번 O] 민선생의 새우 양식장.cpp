#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14.5 02번 O] 민선생의 새우 양식장
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j< 5; j++) {
			cin >> a[i][j];
		}
	}

	if (n == 1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j <= i; j++) {
				cout << a[i][j] << " ";
			}cout << '\n';
		}
	}
	else if (n == 2) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5 - i; j++) {
				cout << a[i][j] << " ";
			}cout << '\n';
		}
	}
	return 0;
}
