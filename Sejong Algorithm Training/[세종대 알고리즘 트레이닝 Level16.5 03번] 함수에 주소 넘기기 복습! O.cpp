#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 03번] 함수에 주소 넘기기 복습! O
문제:
접근:
풀이:
시간복잡도: O()
*/
int a[5][5];
int maxN = 0, maxRow, maxCol;
int minN, minRow, minCol;

void maxIdx() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (maxN < a[i][j]) {
				maxN = a[i][j];
				maxRow = i;
				maxCol = j;
			}
		}
	}
	cout << "(" << maxRow << "," << maxCol << ")" << '\n';
	return;
}

void minIdx() {
	minN = a[0][0];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (minN > a[i][j]) {
				minN = a[i][j];
				minRow = i;
				minCol = j;
			}
		}
	}
	cout << "(" << minRow << "," << minCol << ")" << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	//2.최대 출력
	maxIdx();
	// 최소 출력
	minIdx();
	return 0;
}
