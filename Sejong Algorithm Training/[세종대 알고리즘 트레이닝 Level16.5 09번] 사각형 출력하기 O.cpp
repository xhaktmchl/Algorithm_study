#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 09번] 사각형 출력하기 O
문제:
접근:
풀이:
시간복잡도: O(n*n*2)
*/
int a, b;
char ch;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a >> b>>ch;
	//2.a행, b열 을 2 번 출력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < a; j++) {
			for (int p = 0; p < b; p++) {
				cout << ch;
			}cout << '\n';
		}cout << '\n';
	}
	return 0;
}
