#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 01번 O] 어디에 숨었을까 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10] = { 2,1,2,4,5 };
int b[5][5] = {
	{2,5,3},
	{4,5,7},
	{8,7,2}
};
int n, cnt=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;

	for (int i = 0; i < 5; i++) {
		if (a[i] == n) { cnt++; }
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (b[i][j] == n) { cnt++; }
		}
	}

	cout << cnt;
	return 0;
}
