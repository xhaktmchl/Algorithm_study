#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 01번 O] 너에게 가려면
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 이중반복으로 A,B탐색
	// 찾으면 각 좌표 저장
	//3.출력: 각 행렬의 차이의 합
시간복잡도: O()=
*/
char a[10][10];
int rowA = 0, colA = 0 ,rowB, colB;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.완탐: 이중반복으로 A,B탐색
	// 찾으면 각 좌표 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 'A') { rowA = i; colA = j; }
			if (a[i][j] == 'B') { rowB = i; colB = j; }
		}
	}
	//3.출력: 각 행렬의 차이의 합
	cout << abs(rowB - rowA) + abs(colB - colA);
	return 0;
}
