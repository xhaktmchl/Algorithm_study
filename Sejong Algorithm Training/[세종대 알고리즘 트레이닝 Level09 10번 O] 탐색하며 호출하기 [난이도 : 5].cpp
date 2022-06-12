#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 10번 O] 탐색하며 호출하기 [난이도 : 5]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10];

int checkChar(char ch) {
	if (ch >= 'a' && ch < 'z') { return 0; }
	if (ch >= 'A' && ch <= 'Z') { return 1; }
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 5; i++) {
		if (checkChar(a[i]) == 0) { cout << "소"; }
		else { cout << "대"; }
	}
	return 0;
}
