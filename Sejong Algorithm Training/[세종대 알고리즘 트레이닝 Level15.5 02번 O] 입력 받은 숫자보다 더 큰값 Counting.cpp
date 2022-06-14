#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 02번 O] 입력 받은 숫자보다 더 큰값 Counting
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10][10] = {
	{5,1,4,2,6},
	{3,5,0,0,7},
	{9,9,8,3,1}
};

int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] > n) { cnt++; }
		}
	}

	cout << cnt<<"개";
	return 0;
}
