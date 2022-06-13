#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 11번 O] 원하는 값만 따로 빼오기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[5][5] = {
	{1,3,6,2},
	{4,2,4,5},
	{6,3,7,3},
	{1,5,4,6}
};
int sel[16];
int idx = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] > n) {
				sel[idx++] = a[i][j];
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		cout << sel[i] << " ";
	}
	return 0;
}
