#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 08번 O] 마스킹하고 난뒤
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 좌표에서 마스킹의 최대합 좌표 구하기
	//1)각 좌표에서 마스킹 배열 체크
	//4칸 좌표
	//범위검사
	//마스킹이 1 이면 합
	//2)합이 최대면 최댓값 저장, 좌표 저장
	//3.출력:
시간복잡도: O(3*3*4)=
*/
int Map[5][5] = {
	{3,5,1},
	{3,8,1},
	{1,1,5}
};

int mask[3][3];
int dx[] = { 0,1,1,0 };
int dy[] = { 0,0,1,1 };
bool flag = 1;
int sum = 0;
int maxS, maxR, maxC;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> mask[i][j];
		}
	}
	//2.완탐: 각 좌표에서 마스킹의 최대합 좌표 구하기
	//1)각 좌표에서 마스킹 배열 체크
	//4칸 좌표
	//범위검사
	//마스킹이 1 이면 합
	//2)합이 최대면 최댓값 저장, 좌표 저장
	maxS = -987987987;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			flag = 1;
			sum = 0;
			for (int p = 0; p < 4; p++) {
				int rr = i + dy[p];
				int cc = j + dx[p];

				if (rr < 0 || rr >= 3 || cc < 0 || cc >= 3) { flag = 0; break; }
				if (mask[dy[p]][dx[p]] == 1) {
					sum += Map[rr][cc];
				}
			}
			if (flag == 1) {
				if (sum > maxS) {
					maxS = sum;
					maxR = i;
					maxC = j;
				}
			}
		}
	}
	//3.출력:
	cout << "(" << maxR << "," << maxC << ")";
	return 0;
}
