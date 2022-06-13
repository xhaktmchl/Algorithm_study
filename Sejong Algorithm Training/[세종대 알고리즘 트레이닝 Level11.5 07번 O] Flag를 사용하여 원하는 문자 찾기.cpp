#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 07번 O] Flag를 사용하여 원하는 문자 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
bool flag = 0;

char a[5][5] = {
	"abd",
	"ewz",
	"qva"
};

void Process(char c) {
	c += 32;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == c) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1) { cout << "존재"; }
	else { cout << "없음"; }
}

void Input() {
	cin >> ch;
	Process(ch);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	Input();
	return 0;
}
