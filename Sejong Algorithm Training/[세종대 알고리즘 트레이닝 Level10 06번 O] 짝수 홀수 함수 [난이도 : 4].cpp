#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 06번 O] 짝수 홀수 함수 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b;

void printData(int num) {
	cout << num<<'\n';
}

void even(int num) {
	printData(num * 2);
}

void odd(int num) {
	printData(num - 10);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;
	if ((a / b) %2== 0) {
		even(a / b);
	}
	else {
		odd(a / b);
	}

	printData(a + b);
	return 0;
}
