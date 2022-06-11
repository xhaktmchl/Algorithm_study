#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 04번 O] 문자를 구분해주기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char input;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> input;
	if (input >= 'a' && input <= 'z') { cout << "소문자입력!!"; }
	if (input >= 'A' && input <= 'Z') { cout << "대문자입력!!"; }
	if (input >= '0' && input <= '9') { cout << "숫자문자입력!!"; }
    return 0;
}
