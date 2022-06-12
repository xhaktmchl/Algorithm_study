#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 02번 O] 2차 배열에서 값찾기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
char a[5][10] = {
	"ABCDE",
	"EABAB",
	"ACDER"
};
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> ch;

	for (int i= 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == ch) { cnt++; }
		}
	}

	if (cnt >= 3) { cout << "대발견"; }
	else if (cnt >= 1) { cout << "발견"; }
	else { cout << "미발견"; }
	return 0;
}
