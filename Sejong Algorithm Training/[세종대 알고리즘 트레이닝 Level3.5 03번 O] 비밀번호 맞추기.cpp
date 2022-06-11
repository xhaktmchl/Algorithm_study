#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level3.5 03번 O] 비밀번호 맞추기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];
int result[10] = { 1,2,3,4 };
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] != result[i]) { flag = 0; }
	}
	if (flag == 1) {
		cout << "로그인성공";
	}
	else { cout << "로그인실패"; }
    return 0;
}
