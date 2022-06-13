#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 10번 O] 숫자 하나 입력받고 전역배열에서 값 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10][10] = {
	{3,2,6,2,4},
	{1,4,2,6,5}
};

int KFC(int tar) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == tar) { return 1; }
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int tar;
	cin >> tar;
	if (KFC(tar) == 1) {
		cout << "값이 존재합니다";
	}
	else { cout << "값이 없습니다"; }
	return 0;
}
