#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06 11번 O] 두개의 문자를 4번 출력하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2;
	for (int i = 0; i < 4; i++) {
		for (char j = ch1; j <= ch2; j++) {
			cout << j << " ";
		}cout << '\n';
	}
    return 0;
}
