#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 02번] 안나오는 숫자는? O
문제:
접근:
풀이:
시간복잡도: O(n*n)=3*3
*/
int a[5][5] = {
	{3,5,5},
	{1,4,9},
	{2,2,1}
};

bool check[15];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 배역
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	//2.완탐: 이중 반복, 각 숫자 마스킹
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check[a[i][j]] = 1;
		}
	}
	//3.출력: 숫자 배열 마스킹 안된 것
	for (int i = 1; i <= 9; i++) {
		if (check[i] == 0) {
			cout << i << " ";
		}
	}
	return 0;
}
