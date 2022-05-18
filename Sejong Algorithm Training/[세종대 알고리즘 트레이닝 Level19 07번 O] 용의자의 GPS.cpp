#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 07번 O] 용의자의 GPS
문제:
접근: 구현
풀이:
	//1.입력: 좌표
	//2.완탐: input배열 좌표위치에 5저장
	//3.출력: vect
시간복잡도: O()=
*/
int input[5][5];
int vect[5][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 좌표
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> input[i][j];
		}
	}
	//2.완탐: input배열 좌표위치에 5저장
	for (int i = 0; i < 4; i++) {
		int r = input[i][0];
		int c = input[i][1];
		vect[r][c] = 5;
	}
	//3.출력: vect
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << vect[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
