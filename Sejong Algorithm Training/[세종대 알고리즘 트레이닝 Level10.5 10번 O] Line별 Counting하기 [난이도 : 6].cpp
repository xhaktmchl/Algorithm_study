#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 10번 O] Line별 Counting하기 [난이도 : 6]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10][10] = {
	{1,0,0,0,0},
	{1,0,1,0,0},
	{1,1,0,1,0},
	{1,0,1,0,0},
	{0,1,0,0,1},
	{0,0,0,1,0},
	{1,1,0,0,0}
};

void INPUT() {
	cin >> n;
}

int PROCESS(int num) {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i][num] == 1) { cnt++; }
	}

	return cnt;
}

void OUTPUT(int cnt) {
	cout << cnt;
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	INPUT();
	OUTPUT(PROCESS(n));
	return 0;
}
