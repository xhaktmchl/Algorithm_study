#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 11번] 비트배열로 마스킹 처리하기 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=3*3
*/
int Data[10] = { 3,5,4,2 };
int a[10];
int sum = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 마스킹
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.완탐: 마스킹 된 곳 합 
	for (int i = 0; i < 4; i++) {
		if (a[i] == 1) {
			sum += Data[i];
		}
	}
	//3.출력
	cout << sum;
	return 0;
}
