#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 10번] masking 후 범위안의 숫자 존재여부 구하기 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=3*3
*/
int a[5][5] = {
	{3,1,9},
	{7,2,1},
	{1,0,8}
};
int mask[5][5];
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.마스킹 입력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> mask[i][j];
		}
	}
	//2.완탐: 배열안에 마스킹 되었고 3~5 사이 숫자 존재하면 flag=1
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mask[i][j] == 1 && (a[i][j] >= 3 && a[i][j] <= 5)) {
				flag = 1;
			}
		}
	}
	//3.출력: 
	if (flag == 1) { cout << "발견"; }
	else { cout << "미발견"; }
	return 0;
}
