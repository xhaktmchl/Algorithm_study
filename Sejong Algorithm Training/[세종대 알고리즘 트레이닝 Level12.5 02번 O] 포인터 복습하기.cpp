#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 02번 O] 포인터 복습하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b;
char c, d;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c >> d;
	
	int* p1 = &a;
	int* p2 = &b;
	char* p3 = &c;
	char* p4 = &d;

	for (int i = 0; i < *p1; i++) {
		cout << *p3;
	}cout << '\n';
	for (int i = 0; i < *p2; i++) {
		cout << *p4;
	}
	return 0;
}
