#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 1992 c++ O] 쿼드트리
문제: 2차원 영상을 입력받고 4분면으로 나누어 0,1중 같은 숫자이면 그 숫자로 압축
접근: 2차원 -> 4분면 -> 4분할 정복 재귀 -> 재귀순서(왼위, 오른 위, 왼 아래, 오른 아래)
시간복잡도: O(4^6) ?? 
풀이1:
1.그래프 문자열로 입력받고 2차원 배열에 정수형으로 저장
2.(0,0) 부터 분할 재귀 시작(행,렬,사분면 크기) -> 현재 시작 위치로부터 사분면 크기만큼 같은 숫자인지 완탐
-> 아니면 4분할 재귀순서(왼위, 오른 위, 왼 아래, 오른 아래), (는 왼위 사분면 시작전에 출력, )는 오른아래 사분면 마치고 출력)-> 같은 숫자면 0,1중 압축출력
3.재귀 종료조건, 영상크기 1일때 예외처리
*/
#define MAX 64+1
int n;
int a[MAX][MAX];

void div_con(int row, int col, int N) {
	if (N == 1) {
		if (a[row][col] == 0) { cout << 0; }
		if (a[row][col] == 1) { cout << 1; }
		return;
	}
	
	// 영상의 숫자 완탐
	for (int i = row; i < row+N; i++) {
		for (int j = col; j < col+N; j++) {
			if (a[i][j] != a[row][col]) {
				// 4분할 재귀
				cout << '('; // 왼쪽 위 영상 시작시 ( 괄호
				div_con(row, col, N / 2); // 왼쪽 위
				div_con(row, col+N/2, N / 2); // 오른쪽 위
				div_con(row+N/2, col, N / 2); // 왼 아래
				div_con(row+N/2, col+N/2, N / 2); // 오른 아래
				cout << ')'; // 오른쪽 아래 영상 시작시 ) 괄호
				return;
			}
		}
	}

	if (a[row][col] == 0) { cout << 0; }
	if (a[row][col] == 1) { cout << 1; }
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//그래프 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	div_con(0, 0, n); // 0행0열 부터 분할정복 시작
	return 0;
}
