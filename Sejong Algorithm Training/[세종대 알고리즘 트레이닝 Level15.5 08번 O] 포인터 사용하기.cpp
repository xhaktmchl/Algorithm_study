#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 08번 O] 포인터 사용하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2, ch3;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2 >> ch3;
	char* p1 = &ch1;
	char* p2 = &ch2;
	char* p3 = &ch3;

	if (*p1 > * p2) {
		swap(*p1, *p2);
	}
	if (*p2 > *p3) {
		swap(*p2, *p3);
	}

	cout << *p3;
	return 0;
}
