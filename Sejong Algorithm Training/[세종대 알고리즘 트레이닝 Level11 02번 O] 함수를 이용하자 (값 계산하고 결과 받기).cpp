#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 02번 O] 함수를 이용하자 (값 계산하고 결과 받기)
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

int sum(int a, int b) {
	return a + b;
}

int comp(int a, int b) {
	return abs(a - b);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int a, b;
	cin >> a >> b;
	cout << "합:" << sum(a, b) <<'\n'<< "차:" << comp(a, b);
	return 0;
}
