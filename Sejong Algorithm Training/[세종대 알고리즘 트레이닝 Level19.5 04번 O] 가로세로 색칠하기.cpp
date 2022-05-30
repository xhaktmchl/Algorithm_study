#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 04번 O] 가로세로 색칠하기
문제:
접근: 
풀이: 구현
	//1.입력, 3번
	//2.색칠하기
	//1)가로이면
	//해당 행 전부 색칠
	//2)세로이면
	//해당 열 전부 색칠
	//3.출력
시간복잡도: O()=
*/
char op;
int idx;
int a[10][10];


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력, 3번
	for (int i = 0; i < 3; i++) {
		//2.색칠하기
	//1)가로이면
	//해당 행 전부 색칠
	//2)세로이면
	//해당 열 전부 색칠
		cin >> op >> idx;
		if (op == 'G') {
			for (int j = 0; j < 4; j++) {
				a[idx][j] = 1;
			}
		}
		if (op == 'S') {
			for (int j = 0; j < 4; j++) {
				a[j][idx] = 1;
			}
		}

	}
	//3.출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
