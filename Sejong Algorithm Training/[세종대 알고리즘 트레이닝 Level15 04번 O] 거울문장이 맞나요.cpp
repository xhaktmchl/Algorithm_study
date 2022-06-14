#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 04번 O] 거울문장이 맞나요
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string a, b;
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;

	int len = a.size();
	if (a.size() != b.size()) { flag = 0; }
	else {
		for (int i = 0; i < len; i++) {
			if (a[i] != b[len - 1 - i]) { flag = 0; }
		}
	}

	if (flag == 1) {
		cout << "거울문장";
	}
	else { cout << "거울문장아님"; }
	return 0;
}
