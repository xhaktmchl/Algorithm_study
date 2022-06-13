#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 06번 O] 문자의 위치를 구해주는 함수 만들기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2, ch3;
char a[10] = "MINQUEST";

void Length(char ch) {
	for (int i = 0; i < 8; i++) {
		if (a[i] == ch) {
			cout << ch << "=" << i << '\n';
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2 >> ch3;
	Length(ch1);
	Length(ch2);
	Length(ch3);
	return 0;
}
