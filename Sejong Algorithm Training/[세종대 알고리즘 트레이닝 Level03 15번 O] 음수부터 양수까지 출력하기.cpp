#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level03 15번 O] 음수부터 양수까지 출력하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = -5; i <= 5; i++) {
		cout << i << " ";
	}
    return 0;
}
