#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 1780 c++ V] 종이의 개수
문제: 2차원 종이에 같은 숫자로 이루어지지 않으면 9분할 , 같은 숫자로 이루어저 있으면 각 종이의 갯수 구하기
접근1: 9분할 정복 재귀 -> 재귀(행,렬,종이의 크기) -> 9분할 시작 위치
시간복잡도: O() ??
풀이1:
2차원 그래프 입력
분할정복 재귀(행,렬,종이의 크기)-> 주어진 행렬좌표에서 종이가 같은 숫자인지 완탐 -> 틀리면 9분할 재귀
-> 9분할 시작위치(행+(0*종이크기,1*종이크기,2*종이크기)(열+(0*종이크기,1*종이크기,2*종이크기))
모두 같은 숫자이면 해당 숫자 변수 증가
*/
#define MAX 2200
int n,minu=0,zero=0,plu=0;
int a[MAX][MAX];

void div_con(int row, int col, int N) {
	// 종료조건 크기가 1인 경우 
	if (N == 1) {
		if (a[row][col] == -1) { minu++; }
		if (a[row][col] == 0) { zero++; }
		if (a[row][col] == 1) { plu++; }
		return;
	}
	
	// 모두가 같은 숫자인지 완탐
	for (int i = row; i < row+N; i++) {
		for (int j = col; j < col+N; j++) {
			// 같은 숫자 아닌경우 9분할 재귀
			if (a[row][col] != a[i][j]) {
				for (int r = 0; r < 3; r++) {
					for (int c = 0; c < 3; c++) {
						div_con(row + r * N / 3, col + c * N / 3, N / 3); // 9분할 시작 행렬 위치
					}
				}
				return;
			}
		}
	}
	// 모두 같은 숫자인 경우 
	if (a[row][col] == -1) { minu++; }
	if (a[row][col] == 0) { zero++; }
	if (a[row][col] == 1) { plu++; }
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 그래프 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	div_con(0, 0, n); // 분할정복
	cout << minu << '\n';
	cout << zero << '\n';
	cout << plu << '\n';
	return 0;
}
