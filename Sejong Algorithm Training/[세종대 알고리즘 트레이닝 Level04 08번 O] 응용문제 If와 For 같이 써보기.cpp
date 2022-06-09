#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level04 08번 O] 응용문제 If와 For 같이 써보기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if (n > 5) {
		for (int i = 1; i <= 10; i++) {
			cout << i << '\n';
		}
	}
	else {
		for (int i = 5; i >= 1; i--) {
			cout << i << '\n';
		}
	}
    return 0;
}
