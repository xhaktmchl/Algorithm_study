#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14.5 04번 O] ABC 마트
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct Mart {
	int str;
	int me;
	int wa;
}M;
char ch;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	M A = { 300,500,1000 }, B = { 450,450,900 }, C = { 200,150,700 };

	cin >> ch;
	if (ch == 'A') {
		cout << (A.str + A.me + A.wa) / 3;
	}
	else if (ch == 'B') {
		cout << (B.str + B.me + B.wa) / 3;
	}
	else if(ch == 'C') {
		cout << (C.str + C.me + C.wa) / 3;
	}
	return 0;
}
