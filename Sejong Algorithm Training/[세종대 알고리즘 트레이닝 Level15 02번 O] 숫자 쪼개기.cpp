#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 02번 O] 숫자 쪼개기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	int d = n % 10;
	n  /= 10;
	int c = n % 10;
	n /= 10;
	int b = n % 10;
	n /= 10;
	int a = n;

	cout << "숫자" << a << '\n';
	cout << "숫자" << b << '\n';
	cout << "숫자" << c << '\n';
	cout << "숫자" << d << '\n';
	return 0;
}
