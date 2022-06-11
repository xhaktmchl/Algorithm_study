#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 07번 O] 문자 2개 입력받고 대소문자 바꾸기 [난이도 : 5]
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
	if (ch1 >= 'a' && ch1 <= 'z') { cout << (char)(ch1 - 32) << " "; }
	else if (ch1 >= 'A' && ch1 <= 'Z') { cout << (char)(ch1 + 32) << " "; }

	if (ch2 >= 'a' && ch2 <= 'z') { cout << (char)(ch2 - 32) << " "; }
	else if (ch2 >= 'A' && ch2 <= 'Z') { cout << (char)(ch2 + 32) << " "; }
    return 0;
}
