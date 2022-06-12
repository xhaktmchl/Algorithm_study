#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 05번 O] 번호 순서대로 [난이도 : 4]
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
	if (n % 5 == 1) {
		int tp[5][5] = {
			{9,6,3},
			{8,5,2},
			{7,4,1}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = tp[i][j];
			}
		}
	}
	else if (n % 5 == 2) {
		int tp[5][5] = {
			{7,8,9},
			{4,5,6},
			{1,2,3}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = tp[i][j];
			}
		}
	}
	else {
		int tp[5][5] = {
			{10,13,16},
			{11,14,17},
			{12,15,18}
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = tp[i][j];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
