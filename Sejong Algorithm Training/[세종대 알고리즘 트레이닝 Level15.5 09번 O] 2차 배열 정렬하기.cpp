#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 09번 O] 2차 배열 정렬하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[3][5];
int b[10];
int idx = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			b[idx] = a[i][j];
			idx++;
		}
	}

	sort(b, b + 6);

	idx = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = b[idx];
			idx++;
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
