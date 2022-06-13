#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 01번 O] 함수로부터 값 보내고 받기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

int input() {
	int n;
	cin >> n;
	return n;
}

void calc(int a, int b, int c) {
	cout << a + b + c;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int a, b, c;
	a = input();
	b = input();
	c = input();

	calc(a, b, c);
	return 0;
}
