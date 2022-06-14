#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 13번 O] 2차배열 정렬하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
char a[2][10] = {
	"DATAW",
	"BBQK"
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if (n % 2 == 1) {
		sort(a[0], a[0] + 5);
	}
	else {
		sort(a[1], a[1] + 4);
	}

	for (int i = 0; i < 5; i++) {
		cout << a[0][i];
	}cout << '\n';
	for (int i = 0; i < 4; i++) {
		cout << a[1][i];
	}
	return 0;
}
