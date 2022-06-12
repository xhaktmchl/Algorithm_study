#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08.5 05번 O] 기차 만들기 (Level5 복습) [난이도 : 1]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2>>n;
	for (int i = 0; i < n; i++) {
		for (char i = ch1; i <= ch2; i++) {
			cout << i;
		}cout << '\n';
	}
	return 0;
}
