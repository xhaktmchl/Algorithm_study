#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 03번] 비트배열 합 구하기 O
문제:
접근:
풀이:
시간복잡도: O(n*n)
*/
int a[5][5] = {
	{3,5,9},
	{4,2,1},
	{1,1,5}
};
int b[5][5];
int sum = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.배열 입력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> b[i][j];
		}
	}
	//2.배열 완탐(색칠된 곳 합 구하기)
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (b[i][j] == 1) {
				sum += a[i][j];
			}
		}
	}
	//3.합 출력
	cout << sum;
	return 0;
}
