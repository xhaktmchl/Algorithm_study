#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 03번 O] 배열에서 입력받은 값 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
char a[10][10] = {
	"DAD",
	"QWQ",
	"ASD",
	"ASD"
};
bool flag = 0;

void find(char ch) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == ch) {
				flag = 1;
			}
		}
	}

	if (flag == 1) { cout << "존재"; }
	else { cout << "없음"; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	find(ch);
	return 0;
}
