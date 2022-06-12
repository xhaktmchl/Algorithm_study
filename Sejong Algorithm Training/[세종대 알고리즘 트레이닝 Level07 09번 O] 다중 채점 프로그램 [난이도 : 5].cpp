#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 09번 O] 다중 채점 프로그램 [난이도 : 5]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 5; i++) {
		if (a[i] >= 70) { cout << i+1 << "번사람은" << a[i] << "점PASS" << '\n'; }
		else if(a[i]>=50){ cout << i+1 << "번사람은" << a[i] << "점RETEST" << '\n'; }
		else  { cout << i+1 << "번사람은" << a[i] << "점FAIL" << '\n'; }
	}
    return 0;
}
