#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 01주차 문제06] 숫자 중복 검사 O
문제: 
접근: 
풀이: 
시간복잡도: 
*/
int a[10] = { 3,7,2,5,1,2,9 };
bool dup[10];
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 중복 검사
	for (int i = 0; i < 7; i++) {
		if (dup[a[i]] == 1) {
			flag = 0;
			break;
		}
		else { dup[a[i]] = 1; }
	}
	if (flag) { cout << "안중복" << '\n'; }
	else { cout << "중복" << '\n'; }
	return 0;
}
