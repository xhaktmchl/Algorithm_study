#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 01번 O] ASCII값 출력하기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2;
	cout << "문자'" << ch1 << "'의 아스키코드값은 " << (int)ch1 << '\n';
	cout << "문자'" << ch2 << "'의 아스키코드값은 " << (int)ch2 << '\n';
    return 0;
}
