#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 03번 O] 배열 그대로 화면에 출력 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5] = {
	{3,1,1},
	{2,3,2}
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}
	}
    return 0;
}
