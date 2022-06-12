#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 08번 O] 홀수 짝수는 몇개? [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5] = {
	{3,4,1},
	{2,1,4},
	{3,3,0}
};
int cnt1 = 0, cnt2 = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] % 2 == 0) {
				cnt1++;
			}
			else { cnt2++; }
		}
	}
	cout << "짝수 : " << cnt1 << '\n';
	cout << "홀수 : " << cnt2;
    return 0;
}
