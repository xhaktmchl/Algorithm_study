#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 04번 V] 중력문제
문제:
접근: 
풀이: 완탐, 구현
	//1.입력:
	//2.ㅇ완탐: 이차배열 3-2부터 올라가며
	// 만약 문자이고 아래 좌표에 문자가 없을 때 까지 반복,
	//3.출력
시간복잡도: O()=
*/
char ship[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력: 
	for (int i = 0; i < 4; i++) {
		cin >> ship[i];
	}
	//2.ㅇ완탐: 이차배열 3-2부터 올라가며
	// 만약 문자이고 아래 좌표에 문자가 없을 때 까지 반복,
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			if (ship[i][j] != '_') {
				int row = i;
				while (1) {
					row += 1;
					if (row < 4 && ship[row][j]=='_') {
						char tp = ship[row-1][j];
						ship[row-1][j] = ship[row][j];
						ship[row][j] = tp;
					}
					if (row >= 4) { break; }
				}
			}
		}
	}
	//3.출력
	for (int i = 0; i < 4; i++) {
		cout << ship[i] << '\n';
	}
	return 0;
}
