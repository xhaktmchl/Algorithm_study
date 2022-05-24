#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 07번 O] 바둑이 게임
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.흰 바둑알 놓기(y,x);
	//3.완탐: 각 좌표에서
	//검은돌이면 상우좌하 흰돌인지
	// 상우좌하 흰돌이면 카운트
	//4.출력;
시간복잡도: O()=
*/
int Map[10][10] = {
	{0,0,0,0,0,0,0},
	{0,0,2,0,2,0,0},
	{0,2,1,0,1,2,0},
	{0,0,2,1,2,0,0},
	{0,0,1,2,0,2,0},
	{0,2,2,0,0,0,0},
	{0,0,0,0,0,0,0}
};
int row, col;
int dx[4] = { 0,1,0,-1 };//상우하좌
int dy[4] = { -1,0,1,0 };
int cnt = 0;
int result = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> row >> col;
	//2.흰 바둑알 놓기(y,x);
	Map[row][col] = 2;
	//3.완탐: 각 좌표에서
	//검은돌이면 상우좌하 흰돌인지
	// 범위검사
	// 상우좌하 흰돌이면 카운트
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cnt = 0;
			if (Map[i][j] == 1) {
				for (int p = 0; p < 4; p++) {
					int rr = i + dy[p];
					int cc = j + dx[p];
					if (rr < 0 || rr>6 || cc < 0 || cc>6) { continue; }
					if (Map[rr][cc] == 2) { cnt++; }
				}
				if (cnt == 4) { result++; }
			}
		}
	}
	//4.출력;
	cout << result;
	return 0;
}
