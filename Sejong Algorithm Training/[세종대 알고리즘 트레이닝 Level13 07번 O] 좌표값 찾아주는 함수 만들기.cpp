#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13 07번 O] 좌표값 찾아주는 함수 만들기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[5][5] = {
	"ADF",
	"QWE",
	"ZXC"
};

void find(char ch,int* r,int *c) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == ch) {
				*r = i;
				*c = j;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char ch;
	int r, c;
	cin >> ch;
	find(ch,&r,&c);

	cout << r << "," << c;
	return 0;
}
