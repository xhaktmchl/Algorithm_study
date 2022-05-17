#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 08번 O] 원하는 패턴의 크기 적용
문제:
접근: 완탐
풀이:
	//1.입력: 필터킈기
	//2.완탐: 배열 각 자리에서 필터 탐색
	// 행 범위 검사
	// 열 범위검사
	// 필터 내 합 구하기
	// 최댓값갱신 및 좌표 저장
	//3.출력:
시간복잡도: O(r*c)=
*/
int r, c;
int a[10][10] = {
	{3,5,4,2,5},
	{3,3,3,2,1},
	{3,2,6,7,8},
	{9,1,1,3,2}
};
int sum = 0;
int maxS = -1, maxR = -1, maxC = -1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 필터키기
	cin >> r >> c;
	//2.완탐: 배열 각 자리에서 필터 탐색
	// 행 범위 검사
	// 열 범위검사
	// 필터 내 합 구하기
	// 최댓값갱신 및 좌표 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			sum = 0;
			if (i + r - 1 > 3) { break; }
			if (j + c - 1 > 4) { break; }
			for (int p = i; p < i + r; p++) {
				for (int q = j; q < j + c; q++) {
					sum += a[p][q];
				}
			}
			if (sum > maxS) {
				maxS = sum;
				maxR = i;
				maxC = j;
			}
		}
	}
	//3.출력:
	cout << "(" << maxR << "," << maxC << ")";
	return 0;
}
