#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 01번] 좋아하는 메뉴 찾기 O
문제:
접근:
풀이:
시간복잡도: O(n)
*/
char ar[5] = "MTKC";
char ch;

int isExist(char target) {
	for (int i = 0; i < 4; i++) {
		if (ar[i] == target) {
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> ch;
	//2.문자 유무 탐색
	int result = isExist(ch);
	//3.출력
	if (result == 1) { cout << "발견"; }
	else { cout << "미발견"; }
	return 0;
}
