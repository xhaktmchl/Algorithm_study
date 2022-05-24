#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 08번 O] 모델 위치 지시하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char model;
string op;
int xa=0, xk=2, xt=1,ya=2,yk=2,yt=2;
int a[10][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	for (int i = 0; i < 7; i++) {
		//1.입력: 7반복 명령
		cin >> model >> op;
	//2.완탐:
	//1)A
	//상
	//우
	//좌
	//하
	//2)K
	//상
	//우
	//좌
	//하
	//3)T
	//상
	//우
	//좌
	//하
		if (model == 'A') {
			if (op == "UP") {
				ya -= 1;
			}
			else if (op == "RIGHT") {
				xa += 1;
			}
			else if (op == "DOWN") {
				ya += 1;
			}
			else if (op == "LEFT") {
				xa -= 1;
			}
		}
		else if (model == 'K') {
			if (op == "UP") {
				yk -= 1;
			}
			else if (op == "RIGHT") {
				xk += 1;
			}
			else if (op == "DOWN") {
				yk += 1;
			}
			else if (op == "LEFT") {
				xk -= 1;
			}
		}
		else if (model == 'T') {
			if (op == "UP") {
				yt -= 1;
			}
			else if (op == "RIGHT") {
				xt += 1;
			}
			else if (op == "DOWN") {
				yt += 1;
			}
			else if (op == "LEFT") {
				xt -= 1;
			}
		}
	}
	
	//3.출력: 배열
	a[ya][xa] = 1;
	a[yk][xk] = 2;
	a[yt][xt] = 3;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 0) {
				cout << "_";
			}
			else if (a[i][j] == 1) {
				cout << "A";
			}
			else if (a[i][j] == 2) {
				cout << "K";
			}
			else if (a[i][j] == 3) {
				cout << "T";
			}
		}cout << '\n';
	}
	return 0;
}
