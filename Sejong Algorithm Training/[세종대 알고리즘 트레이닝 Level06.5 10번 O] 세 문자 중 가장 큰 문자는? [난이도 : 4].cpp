#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 10번 O] 세 문자 중 가장 큰 문자는? [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10];
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		if (a[i] > a[0]) { flag = 0; }
	}
	if (flag == 1) { cout << "옳다" << a[0]; }
	else { cout << "옳지않음"; }
    return 0;
}
