#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 04번 O] 입력받은 글자를 세밀히 세보기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
char a[10][10] = {
	"abacz",
	"ctacd",
	"cccca"
};
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == ch) { cnt++; }
		}
	}

	if (cnt >= 7) { cout << "세상에"; }
	else if (cnt >= 5) { cout << "와우"; }
	else if (cnt >= 3) { cout << "이야"; }
	else { cout << "이런"; }
	return 0;
}
