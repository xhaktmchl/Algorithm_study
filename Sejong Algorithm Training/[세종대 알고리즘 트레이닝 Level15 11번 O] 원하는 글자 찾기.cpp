#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 11번 O] 원하는 글자 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string str[5];
bool flagA = 0, flagB = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}

	for (int i= 0; i < 4; i++) {
		int len = str[i].size();
		for (int j = 0; j < len; j++) {
			if (str[i][j] == 'A') { flagA = 1; }
			if (str[i][j] == 'B') { flagB = 1; }
		}
	}

	if (flagA == 1 && flagB == 1) {
		cout << "대발견";
	}
	else if (flagA == 0 && flagB == 0) { cout << "미발견"; }
	else { cout << "중발견"; }
	return 0;
}
