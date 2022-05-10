#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 12번] 레이더 만들기 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=5*5
*/
char a[10][10] = {
	"ABCDE",
	"FGHIJ",
	"KLMNO",
	"PQRST",
	"UVWXY"
};
char tar;
int row, col;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 문자
	cin >> tar;
	//2.완탐: 문자 탐색
	// 찾으면 offset 출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (tar == a[i][j]) {
				row = i - 2;
				col = j - 2;
			}
		}
	}
	cout << row << "," << col;
	return 0;
}
