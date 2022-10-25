#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 05회차 05번 백준 2630 c++ OVO] 색종이 만들기
문제: 같은 숫자로 이루어진 종이의 갯수 세기, 다른 숫자면 4분할
접근1: 4분할 정복 재귀 -> 재귀(행,렬,종이의 크기) -> 4분할 시작 위치(왼쪽 위, 오른쪽 위, 왼쪽 아래,오른쪽 아레)
시간복잡도: O(4^7) ??
풀이1: 이 문제에선 풀이 1 사용
2차원 그래프 입력
분할정복 재귀(행,렬,종이의 크기)-> 주어진 행렬좌표에서 종이가 같은 숫자인지 완탐 -> 틀리면 4분할 재귀
-> 4분할 시작위치(행+(0*종이크기,1*종이크기)(열+(0*종이크기,1*종이크기))
모두 같은 숫자이면 해당 숫자 변수 증가 , 크기 1 일때는 종이갯수 바로 세줘야 함(종이 크기가 0으로 되기 때문)
풀이 2: 분할정복하는 순서 다름(완탐하는데 시가닝 덜 걸리지만 로직이 간단)
분할정복재귀 -> 종이의 0 갯수 세기 -> 흰종이, 파란종이면 종이 갯수증가-> 아니면 4분할 재귀

풀이:
	//1.입력 n, 그래프
	//2.분할정복 재귀(row, col, N)
	//1)완탐: 2차원 배열 탐색,
	//2)만약 왼쪽 위 숫자와 다른 부분 나오면 재귀
	//왼쪽위 (r,c)
	//오른쪽위 (r,c+n/2)
	//오른쪽 아래(r+n/2,c+n/2)
	//왼쪽아래(r+n/2,c)
	//3)만약 다 통과하면 카운트, 중단
	//3.출력: 0, 1 종이 갯수
시간복잡도: O()= 
개념:
*/
int n;
int a[200][200];
int cnt0=0, cnt1=0;

void div_conq(int row, int col, int N) {
	bool ok = 1;
	for (int i = row; i <row+N; i++) {
		for (int j = col; j < col + N; j++) {
			if (a[i][j] != a[row][col]) {
				ok = 0;
				div_conq(row, col, N / 2);
				div_conq(row, col + N / 2, N / 2);
				div_conq(row + N / 2, col + N / 2, N / 2);
				div_conq(row + N / 2, col, N / 2);
			}
			if (ok == 0) {
				return;
			}
		}
	}
	if (ok == 1) {
		if (a[row][col] == 0) cnt0++;
		if (a[row][col] == 1) cnt1++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력 n, 그래프
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	//2.분할정복 재귀(row, col, N)
	//1)완탐: 2차원 배열 탐색, 
	//2)만약 왼쪽 위 숫자와 다른 부분 나오면 재귀
	//왼쪽위 (r,c)
	//오른쪽위 (r,c+n/2)
	//오른쪽 아래(r+n/2,c+n/2)
	//왼쪽아래(r+n/2,c)
	//3)만약 다 통과하면 카운트, 중단
	div_conq(0, 0, n);
	//3.출력: 0, 1 종이 갯수
	cout << cnt0 << '\n' << cnt1;
	return 0;
}
