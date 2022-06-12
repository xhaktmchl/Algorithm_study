#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 09번 O] Call by value2 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
int cnt = 0;
char a[5][5] = {
	"FEW",
	"DCA"
};

void findCh(char tar) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (a[i][j] == tar) { cnt++; }
		}
	}

	if (cnt > 0) { cout << "발견"; }
	else { cout << "미발견"; }
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> ch;
	findCh(ch);
	return 0;
}
