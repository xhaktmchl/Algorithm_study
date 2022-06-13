#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 09번 O] 원하는 글자만 다른곳에 쌓아두기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10], big[10],small[10];
int idxB = 0, idxS = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 8; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') { big[idxB++] = a[i]; }
		else if (a[i] >= 'a' && a[i] <= 'z') { small[idxS++] = a[i]; }
	}

	cout << "big=";
	for (int i = 0; i < idxB; i++) {
		cout << big[i];
	}cout << '\n'<<"small=";
	for (int i = 0; i < idxS; i++) {
		cout << small[i];
	}
	return 0;
}
