#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 05번] 입력받은 비트배열로 마스킹하기 O
문제:
접근:
풀이:
시간복잡도: O(n)=7
*/
int vect[10] = { 3,5,4,2,6,6,5 };
int bit[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 7; i++) {
		cin >> bit[i];
	}
	//2.완탐: 
	//마스킹 부분 7로 바저장
	//아닌부분 0 저장
	for (int i = 0; i < 7; i++) {
		if (bit[i] == 1) {
			vect[i] = 7;
		}
		else { vect[i] = 0; }
	}
	//3.출력
	for (int i = 0; i < 7; i++) {
		cout << vect[i];
	}
	return 0;
}
