#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 07번 O] A to Z [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

char aToZ() {
	char ch;
	cin >> ch;

	if (ch - 'A' < 'Z' - ch) {
		return 'A';
	}
	else {
		return 'Z';
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char ret = aToZ();
	cout << ret;
	return 0;
}
