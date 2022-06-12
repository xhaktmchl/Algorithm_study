#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 06번 O] 배열 특정 범위에 값 채우기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10][5] = {
	{10,16,22},
	{11,17,23},
	{12,18,24},
	{13,19,25},
	{14,20,26},
	{15,21,27}
};
int r1, r2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> r1 >> r2;
	for (int i = r1; i <= r2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = 7;
		}
	}

	for (int i= 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
