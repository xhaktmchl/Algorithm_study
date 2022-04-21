#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 04번] offset으로 범인을 찾아라 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=3*4
*/
char a[5][10] = {
	"ATKB",
	"CZFD",
	"HGEI"
};
char ch;
int y, x,row,col;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> ch >> y >> x;
	//2.완전 탐색: 문자 위치
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == ch) {
				row = i;
				col = j;
			}
		}
	}
	//3.출력:문자 위치로부터 행,렬 더한 위치 문자
	cout << a[row + y][col + x];
	return 0;
}
