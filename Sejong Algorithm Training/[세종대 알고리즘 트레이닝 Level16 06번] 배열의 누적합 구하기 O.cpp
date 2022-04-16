#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 06번] 배열의 누적합 구하기 O
문제: 
접근: 
풀이: 완탐
시간복잡도: O(n)
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 1.입력
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	// 2.누적합
	for (int i = 1; i < 6; i++) {
		a[i] = a[i - 1] + a[i];
	}
	// 3.출력
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
