#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08.5 02번 O] 내 친구는 어디에? (Level4 복습) [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10] = "DTABWQ";
char ch;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	for (int i = 0; i < 6; i++) {
		if (a[i] == ch) {
			cout << i << "번 INDEX";
			break;
		}
	}
	return 0;
}
