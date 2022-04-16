#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 05번] 마음에 들지 않는 글자 바꾸기 O
문제:
접근:
풀이:
시간복잡도: O()
*/
string str;
char ch1, ch2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str >> ch1 >> ch2;
	// 문자열 탐색
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch1) {
			str[i] = ch2;
		}
	}
	cout << str << '\n';
	return 0;
}
