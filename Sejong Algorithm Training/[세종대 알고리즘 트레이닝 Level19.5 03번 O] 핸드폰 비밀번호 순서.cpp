#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 03번 O] 핸드폰 비밀번호 순서
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 이차배열에서 입력된 배열원소 있는지
	// 있으면 순번 배열에 저장
	//순번 증가
	//3.출력:
시간복잡도: O(4*4*4)=
*/
int a[10];
int Map[10][10] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};
int result[10][10];
int cnt = 1;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.완탐: 이차배열에서 입력된 배열원소 있는지
	// 있으면 순번 배열에 저장
	//순번 증가
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int p = 0; p < 4; p++) {
				if (Map[i][j] == a[p]) {
					result[i][j] = cnt;
					cnt++;
				}
			}
		}
	}
	//3.출력:
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << result[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
