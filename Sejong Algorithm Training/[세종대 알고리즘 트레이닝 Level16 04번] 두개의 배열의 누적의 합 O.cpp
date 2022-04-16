#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 04번] 두개의 배열의 누적의 합 O
문제: 
접근: 
풀이: 
시간복잡도: 
*/
int a[10], b[10], result[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}
	// 배열 계산
	for (int i = 0; i < 4; i++) {
		result[i] = a[i] + b[3 - i];
	}
	// 출력
	for (int i = 0; i < 4; i++) {
		cout << result[i] << " ";
	}
	return 0;
}
