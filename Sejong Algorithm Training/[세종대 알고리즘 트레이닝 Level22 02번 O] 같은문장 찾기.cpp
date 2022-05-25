#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 02번 O] 같은문장 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string st[5];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 3; i++) {
		cin >> st[i];
	}
	if (st[0] == st[1]) { cnt++; }
	if (st[0] == st[2]) { cnt++; }
	if (st[1] == st[2]) { cnt++; }

	if (cnt == 3) {
		cout << "WOW";
	}
	else if (cnt == 2) { cout << "GOOD"; }
	else { cout << "BAD"; }
	return 0;
}
