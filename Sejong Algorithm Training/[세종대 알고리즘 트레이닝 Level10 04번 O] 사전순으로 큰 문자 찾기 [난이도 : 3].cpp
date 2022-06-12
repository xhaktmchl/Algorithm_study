#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 04번 O] 사전순으로 큰 문자 찾기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

char getChar() {
	char ch1, ch2;
	cin >> ch1 >> ch2;

	if (ch1 > ch2) {
		return ch1;
	}
	else { return ch2; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char result = getChar();
	cout << result;
	return 0;
}
