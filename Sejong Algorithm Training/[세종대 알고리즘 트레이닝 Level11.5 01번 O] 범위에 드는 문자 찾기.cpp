#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 01번 O] 범위에 드는 문자 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;
char a[10] = "DFGDAQ";
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2;
	
	for (int i = 0; i < 6; i++) {
		if (a[i] >= ch1 && a[i] <= ch2) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "발견!!!";
	}
	else { cout << "미발견!!!"; }
	return 0;
}
