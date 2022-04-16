#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 02번] 알파벳 순서대로 배열 채우기 O
문제:
접근:
풀이:
시간복잡도: O()
*/
char a[10][10];
int cnt = 0,row,col;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.배열 채우기
	for (int i = 2; i >= 0; i--) {
		for (int j = 5; j >= 0; j--) {
			a[j][i] = 'A' + cnt++;
		}
	}
	//2.좌표 입력
	cin >> row >> col;
	//3.출력
	cout << a[row][col];
	return 0;
}
