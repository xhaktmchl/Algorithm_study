#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 04번 O] 문자 존재여부 판단하기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10][10] = {
	"DACCD",
	"SDFAE",
	"EETJH"
};

int CHECK(char ch) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == ch) {
				return 1;
			}
		}
	}

	return 0;
}

void INPUT() {
	char ch;
	cin >> ch;
	int ret = CHECK(ch);

	if (ret == 1) { cout << "있음"; }
	else { cout << "없음"; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	INPUT();
	return 0;
}
