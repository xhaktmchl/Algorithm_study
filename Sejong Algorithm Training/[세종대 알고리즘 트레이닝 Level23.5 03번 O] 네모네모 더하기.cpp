#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23.5 03번 O] 네모네모 더하기
문제:
접근: 
풀이: 구현
	//1.입력
	//2.가로줄 합 저장
	//3.세로줄 합 저장
	//4.대각선 합
	//5.출력
시간복잡도: O()=
*/
int a[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	//2.가로줄 합 저장
	for (int i = 0; i < 3; i++) {
		a[i][3] = a[i][0] + a[i][1] + a[i][2];
	}
	//3.세로줄 합 저장
	for (int i = 0; i < 3; i++) {
		a[3][i] = a[0][i] + a[1][i] + a[2][i];
	}
	//4.대각선 합
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += a[i][i];
	}
	a[3][3] = sum;
	//5.출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
