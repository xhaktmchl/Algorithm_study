#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 06번 O] A, B, C가 몇개인지 알려주는 함수 만들기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

void FindABC(string a, string b, int* cnta, int* cntb, int* cntc) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'A') { (*cnta)++; }
		if (a[i] == 'B') { (*cntb) += 1; }
		if (a[i] == 'C') { (*cntc) += 1; }

		if (b[i] == 'A') { (*cnta)++; }
		if (b[i] == 'B') { (*cntb) += 1; }
		if (b[i] == 'C') { (*cntc) += 1; }
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int cnta = 0, cntb = 0, cntc = 0;
	string a, b;
	cin >> a >> b;

	FindABC(a, b, &cnta, &cntb, &cntc);

	cout << "A:" << cnta << '\n';
	cout << "B:" << cntb << '\n';
	cout << "C:" << cntc << '\n';
	return 0;
}
