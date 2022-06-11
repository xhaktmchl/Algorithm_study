#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06 12번 O] ABC초콜릿 모으기 [난이도 : 5]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a, b, c, flag;

void input() {
	cin >> a >> b >> c;

}

void process() {
	if (a == 'A' && b == 'B' && c == 'C') {
		flag = 1;
	}
	else {
		flag = 0;
	}
}

void output() {
	if (flag == 1) {
		cout << "ABC를찾았다";
	}
	else { cout << "못찾았다"; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	
	input();
	process();
	output();
    return 0;
}
