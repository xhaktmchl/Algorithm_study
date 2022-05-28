#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 04번 O] 하마의 충치
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 열이 모두 1이면
	//카운트
	//3.출력:
시간복잡도: O(5*2)=
*/
int a[10][10];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	//2.완탐: 각 열이 모두 1이면 
	//카운트
	for (int i = 0; i < 5; i++) {
		if (a[0][i] == 1 && a[1][i] == 1) { cnt++; }
	}
	//3.출력:
	cout << cnt<<"개";
	return 0;
}
