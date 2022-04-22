#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 06번] 합친 mask배열의 좌표 구하기 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=16
*/
int a[5][5] = {
	{0,0,0,1},
	{1,1,0,1},
	{1,0,0,1},
	{1,1,1,1}
};
int b[5][5] = {
	{1,1,1,1},
	{1,0,1,1},
	{1,0,0,0},
	{1,0,0,0}
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.완탐: 배열 합치기
	//비어있는 좌표 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 0 && b[i][j] == 0) {
				cout << "(" << i << "," << j << ")" << '\n';
			}
		}
	}
	return 0;
}
