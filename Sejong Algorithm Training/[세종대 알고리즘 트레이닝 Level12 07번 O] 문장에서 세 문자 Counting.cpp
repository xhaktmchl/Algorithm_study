#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 07번 O] 문장에서 세 문자 Counting
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string a;
char ch1, ch2, ch3;

void cnt(char ch) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ch) {
			cnt++;
		}
	}

	cout << ch << "=" << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a;
	cin >> ch1 >> ch2 >> ch3;

	cnt(ch1);
	cnt(ch2);
	cnt(ch3);
	return 0;
}
