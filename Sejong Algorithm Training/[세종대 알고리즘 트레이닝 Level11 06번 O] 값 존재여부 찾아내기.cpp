#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 06번 O] 값 존재여부 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10] = { 3,4,1,3,2,7,3 };
int n;
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 7; i++) {
		if (a[i] == n) { flag = 1; }
	}

	if (flag == 1) { cout << "발견"; }
	else { cout << "미발견"; }
	return 0;
}
