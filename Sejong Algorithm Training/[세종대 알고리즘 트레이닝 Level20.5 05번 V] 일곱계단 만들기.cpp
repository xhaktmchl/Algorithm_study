#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 05번 V] 일곱계단 만들기
문제:
접근:완탐
풀이:
	//1.입력
	//문자 -3부터+3까지 탐색
	//2.문자가 A보다 작을 경우
	//tp = 'Z' - ('A' - (tp)) + 1;
	//3.문자가 Z보다 클 경우
	//tp = 'A' + ((tp) - 'Z') - 1;
시간복잡도: O()=
*/
char ch;
string result;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> ch;
	//문자 -3부터+3까지 탐색
	//2.문자가 A보다 작을 경우
	//tp = 'Z' - ('A' - (tp)) + 1;
	//3.문자가 Z보다 클 경우
	//tp = 'A' + ((tp) - 'Z') - 1;

	for (int i = -3; i <= 3; i++) {
		char tp = ch + i;
		if (tp < 'A') {
			tp = 'Z' - ('A' - (tp)) + 1;
		}
		else if (tp > 'Z') {
			tp = 'A' + ((tp) - 'Z') - 1;
		}
		result += tp;
	}
	cout << result;
	return 0;
}
