#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 03번 O] 입력받은 문자의 개수
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
char a[10] = "A1115Awz";
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	for (int i = 0; i < 8; i++) {
		if (a[i] == ch) cnt++;
	}

	if (cnt >= 3) { cout << "THREE";}
	else if (cnt == 2) { cout << "TWO"; }
	else if (cnt == 1) { cout << "ONE"; }
	else { cout << "NOTHING"; }
	return 0;
}
