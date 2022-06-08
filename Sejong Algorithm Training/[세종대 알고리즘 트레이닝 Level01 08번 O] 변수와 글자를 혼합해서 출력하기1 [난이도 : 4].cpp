#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level01 08번 O] 변수와 글자를 혼합해서 출력하기1 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a = 5, b = -1, c = 2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cout << "a, b, c 값은 각각 a는 " << a << ", b는 " << b << ", c는 " << c << " 입니다";
	return 0;
}
