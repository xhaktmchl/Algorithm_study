#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 03번 O] 폭탄 투하
문제:
접근: 구현
풀이:
	//1.입력
	//2.폭탄 투하
	//1) 8방향 탐색,
	//범위검사 (행4,열5)
	//#표시
	//3.출력
시간복잡도: O()=
*/
char Map[10][10] = {
	"_____",
	"_____",
	"_____",
	"_____"
};
int r[3], c[3];
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 2; i++) {
		cin >> r[i] >> c[i];
	}
	//2.폭탄 투하
	//1) 8방향 탐색,
	//범위검사 (행4,열5)
	//#표시
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			int rr = r[i] + dy[j];
			int cc = c[i] + dx[j];
			if (rr < 0 || rr >= 4 || cc < 0 || cc >= 5) { continue; }
			Map[rr][cc] = '#';
		}
	}
	//3.출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << Map[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
