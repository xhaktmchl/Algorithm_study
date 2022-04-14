#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 01주차 문제03 O] 1~5 숫자 중 3개의 수 조합
문제: 
접근: 
풀이: 3완탐 중 반복
시간복잡도: 
풀이2: 완탐 재귀
*/
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1~5 숫자 중 3개의 수 조합
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int p = 1; p <= 5; p++) {
				cout << i << "," << j << "," << p << '\n';
			}
		}
	}
	return 0;
}
