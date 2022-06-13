#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 06번 O] 여러 글자 바꾸기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[5][5] = {
	"abE",
	"E2W",
	"324"
};


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] >= 'a' && a[i][j] <= 'z') {
				cout << (char)(a[i][j] - ('a' - 'A')) << " ";
			}
			if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
				cout << (char)(a[i][j] + ('a' - 'A')) << " ";
			}
			if (a[i][j] >= '0' && a[i][j] <= '9') {
				cout << (int)(a[i][j] - '0')+5 << " ";
			}
		}cout << '\n';
	}
	return 0;
}
