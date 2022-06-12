#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 03번 O] KFC 주문하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

int chicken() {
	int n;
	cin >> n;
	return n;
}

char coke() {
	char ch;
	cin >> ch;
	return ch;
}

void KFC() {
	int num = chicken();
	char ch = coke();

	cout << num+10 << ch;
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	KFC();
	return 0;
}
