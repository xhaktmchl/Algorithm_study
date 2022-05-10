#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 08번] 컬러찾기 O
문제:
접근:
풀이:
시간복잡도: O(n*n*n*n)=
*/
int Map[3][5] = {
	{3,55,42},
	{-5,-9,-10}
};
int pix[4][4];
char result[4][4];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> pix[i][j];
		}
	}
	//2.와탐: 각 pix의 숫자값이 map에 있는지 탐색
	// 있으면 flag=1, 중단
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			bool flag = 0;
			for (int p = 0; p < 2; p++) {
				for (int q = 0; q < 3; q++) {
					if (pix[i][j] == Map[p][q]) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) {
				result[i][j] = 'Y';
			}
			else { result[i][j] = 'N'; }
		}
	}
	//3.출력: 결과 배열
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << result[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
