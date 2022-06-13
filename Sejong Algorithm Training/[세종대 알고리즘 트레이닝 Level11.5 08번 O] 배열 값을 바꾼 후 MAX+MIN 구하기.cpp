#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 08번 O] 배열 값을 바꾼 후 MAX+MIN 구하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5] = {
	{3,1,6},
	{7,8,4},
	{9,2,3}
};
int r, c, n,maxN,minN;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> r >> c >> n;
	a[r][c] = n;

	maxN = a[0][0];
	minN = a[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			maxN = max(maxN, a[i][j]);
			minN = min(minN, a[i][j]);
		}
	}

	cout << maxN + minN;
	return 0;
}
