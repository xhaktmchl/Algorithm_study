#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 06번] 금고털이 O
문제:
접근:
풀이:
시간복잡도: O(n)=4
*/
int password[10] = { 3,7,4,9 };
int a[10];
bool flag = 1;

// isSame
// 1)완탐: 배열 원소 비교
void isSame() {
	for (int i = 0; i < 4; i++) {
		if (a[i] != password[i]) {
			flag = 0;
			break;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.input 입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.완탐: 비밀번호 같은지
	isSame();
	//3.출력: pass, fail
	if (flag == 1) {
		cout << "pass";
	}
	else { cout << "fail"; }
	return 0;
}
