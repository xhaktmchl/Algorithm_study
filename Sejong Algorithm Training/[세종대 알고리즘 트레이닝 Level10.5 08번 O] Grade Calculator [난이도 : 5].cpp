#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 08번 O] Grade Calculator [난이도 : 5]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char Calculator() {
	int sc;
	cin >> sc;

	if (sc >= 90) { return 'A'; }
	else if (sc >= 80) { return 'B'; }
	else if (sc >= 70) { return 'C'; }
	else { return 'D'; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char ret = Calculator();
	cout << ret;
	return 0;
}
