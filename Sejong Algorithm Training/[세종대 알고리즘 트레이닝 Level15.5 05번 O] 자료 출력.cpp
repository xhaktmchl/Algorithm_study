#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 05번 O] 자료 출력
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b, c;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {

		for (int i = 0; i < b; i++) {
			cout << a + i << " ";
		}cout << '\n';
	}
	return 0;
}
