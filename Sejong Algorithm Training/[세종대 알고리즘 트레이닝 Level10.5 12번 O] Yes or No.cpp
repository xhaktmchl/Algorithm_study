#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 12번 O] Yes or No
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

int yesOrNo() {
	cin >> n;
	if (n % 3 == 0) { return 7; }
	else if (n % 3 == 1) { return 35; }
	else if (n % 3 == 2) { return 50; }
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cout << yesOrNo();
	return 0;
}
