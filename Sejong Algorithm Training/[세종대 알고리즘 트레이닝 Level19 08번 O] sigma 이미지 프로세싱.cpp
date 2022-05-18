#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 08번 O] sigma 이미지 프로세싱
문제:
접근: 완탐
풀이:
	//1.입력
	//2.완탐: 각 배열 좌표에서 2,3 크기 영역 합 구하기
	//범위검사 행, 열
	//2,3 구역 합 구하기
	//최댓값이면 저장, 좌표 저장
	//3.출력: 최대 행,렬
시간복잡도: O()=
*/
int image[10][10];
int sum = 0, maxS=-987987987,maxR=-1,maxC=-1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> image[i][j];
		}
	}
	//2.완탐: 각 배열 좌표에서 2,3 크기 영역 합 구하기
	//범위검사 행, 열
	//2,3 구역 합 구하기
	//최댓값이면 저장, 좌표 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum = 0; // 초기화
			if (i + 1 > 3 || j + 2 > 3) { continue; } 
			for (int p = i; p < i + 2; p++) {
				for (int q = j; q < j + 3; q++) {
					sum += image[p][q];
				}
			}
			if (sum > maxS) {
				maxS = sum;
				maxR = i;
				maxC = j;
			}
		}
	}
	//3.출력: 최대 행,렬
	cout << "(" << maxR << "," << maxC << ")";
	return 0;
}
