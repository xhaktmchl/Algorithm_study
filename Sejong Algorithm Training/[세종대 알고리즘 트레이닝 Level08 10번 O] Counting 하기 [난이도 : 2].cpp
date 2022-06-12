#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08 10번 O] Counting 하기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5] = {
	{4,3,1,1},
	{3,1,2,1},
	{0,0,1,2}
};
int n, cnt=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == n) { cnt++; }
		}
	} 
	cout << cnt << "개 존재합니다";
	return 0;
}
