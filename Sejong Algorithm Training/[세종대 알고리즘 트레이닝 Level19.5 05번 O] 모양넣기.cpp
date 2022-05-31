#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 05번 O] 모양넣기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 알파벳 대문자 체크
	//3.출력: 입력된 알파벳만
시간복잡도: O(3*3)=
*/
typedef struct sketch{
	char image[5][5];
}S;

bool check[200];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	S s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> s.image[i][j];
		}
	}
	//2.완탐: 각 알파벳 대문자 체크
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check[s.image[i][j]] = 1;
		}
	}
	//3.출력: 입력된 알파벳만
	for (int i = 'A'; i <= 'Z'; i++) {
		if (check[i] == 1) {
			cout << (char)i;
		}
	}
	return 0;
}
