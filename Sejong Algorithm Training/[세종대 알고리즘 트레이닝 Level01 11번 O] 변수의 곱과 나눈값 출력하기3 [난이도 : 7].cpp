#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level01 11번 O] 변수의 곱과 나눈값 출력하기3 [난이도 : 7]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a = 3, b = 5, c = 3, d = 4;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cout << ((a + b) * c) / d;
	return 0;
}
