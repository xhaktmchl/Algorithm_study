#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level05 09번 O] 함수하나 정의하고 호출하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
char a[10] = "ABC";

void KFC() {
	for (int i = 0; i < 3; i++) {
		cout << a[i];
	}cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		KFC();
	}
    return 0;
}
