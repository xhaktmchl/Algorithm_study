#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 05번] isExist함수로 보물찾기 O
문제:
접근:
풀이:
시간복잡도: O(n*n*3)=27
*/
int ar[5][5] = {
	{3,5,9},
	{4,2,1},
	{5,1,5}
};

int a[5];
int result;
// 있으면 1, 없으면 0
int isExist(int num) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ar[i][j] == num) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a[0] >> a[1] >> a[2];
	//2.완탐 각 숫자 맞는지탐색
	//출력(존재, 미발견)
	for (int i = 0; i < 3; i++) {
		result = isExist(a[i]);
		if (result == 1) { cout << a[i] << ":존재" << '\n'; }
		else { cout << a[i] << ":미발견" << '\n'; }
	}
	return 0;
}
