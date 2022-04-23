#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 02번] 합격자 발표일 O
문제:
접근:
풀이:
시간복잡도: O(n*n*6)=
*/
int a[10] = { 3,7,4,1,2,6 };
int check[4][4];
int b[4][4];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> b[i][j];
		}
	}
	//2.완탐: 이중반복으로 각 숫자 있는지 탐색
	//있으면 체크
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int p = 0; p < 6; p++) {
				if (a[p] == b[i][j]) {
					check[i][j] = 1;
				}
			}
		}
	}
	//3.출력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (check[i][j] == 0) {
				cout << "NO ";
			}
			else { cout << "OK "; }
		}cout << '\n';
	}
	return 0;
}
