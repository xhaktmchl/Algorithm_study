#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 04번 O] 한줄a 한줄b
문제:
접근: 
풀이:
	//1.입력
	//2.완탐: 3차원 배열 채우기
	//2차원에서 0 행이면 a
	// 1행이면 b채우기
	//3.출력:
시간복잡도: O(3*2*3)=
*/
int ar[5][5][5];
int a, b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a >> b;
	//2.완탐: 3차원 배열 채우기
	//2차원에서 0 행이면 a
	// 1행이면 b채우기
	for (int t = 0; t < 3; t++) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 0) { ar[t][i][j] = a; }
				else if (i == 1) { ar[t][i][j] = b; }
			}
		}
	}
	//3.출력:
	for (int t = 0; t < 3; t++) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ar[t][i][j] << " ";
			}cout << '\n';
		}cout << '\n';
	}
	return 0;
}
