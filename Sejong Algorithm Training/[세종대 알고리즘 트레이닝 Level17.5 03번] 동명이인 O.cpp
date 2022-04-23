#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 03번] 동명이인 O
문제:
접근:
풀이:
시간복잡도: O(1)=
*/
string st1, st2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.두개의 문자열 입력
	cin >> st1 >> st2;
	//2.출력: 같으면 동명, 다르면 남남
	if (st1 == st2) { cout << "동명"; }
	else { cout << "남남"; }
	return 0;
}
