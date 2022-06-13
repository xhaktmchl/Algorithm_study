#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 01번 O] 구조체 복습하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct NODE {
	int x;
	int y;
}N;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	N a, b;
	cin >> a.x >> b.x;
	a.y = a.x + 5;
	b.y = b.x - 5;

	cout << "ta.x=" << a.x << '\n';
	cout << "ta.y=" << a.y << '\n';
	cout << "tb.x=" << b.x << '\n';
	cout << "tb.y=" << b.y << '\n';
	return 0;
}
