#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 09번 O] 구조체에 배열넣기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct BBQ {
	int x;
	int data[5];
}B;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	B g;
	cin >> g.x;
	for (int i = 0; i < 3; i++) {
		cin >> g.data[i];
	}

	int sum = g.data[0] + g.data[1] + g.data[2];
	cout << sum << " " << g.x;
	return 0;
}
