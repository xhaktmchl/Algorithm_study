#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 11번 O] 알파벳 퀴즈
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char input[10];
char a[10] = "APPLET";
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			if (input[i] == a[j]) { cnt++; }
		}
	}

	cout << cnt << "개 맞추었습니다";
	return 0;
}
