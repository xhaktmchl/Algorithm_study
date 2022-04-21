#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 08번] 두 글자의 존재 여부 O
문제:
접근:
풀이:
시간복잡도: O(n*n)
*/
char a[5][10] = {
	{'A','7','9','T','K','Q'},
	{'M','I','N','C','O','D'}
};

char ch1, ch2;

void isExist(char ch) {
	bool flag = false;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (a[i][j] == ch) {
				flag = true;
				break;
			}
		}
		if (flag) { break; }
	}

	if (flag) {
		cout << ch << " : 존재" << '\n';
	}
	else { cout << ch << " : 없음" << '\n'; }
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> ch1 >> ch2;
	//2.존재 유무 탐색
	isExist(ch1);
	isExist(ch2);
	//3.출력
	return 0;
}
