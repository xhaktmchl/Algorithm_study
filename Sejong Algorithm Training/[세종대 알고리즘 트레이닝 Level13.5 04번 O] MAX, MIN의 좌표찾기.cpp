#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 04번 O] MAX, MIN의 좌표찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5] = {
	{3,4,1,6},
	{3,5,3,6},
	{0,0,0,0},
	{5,4,6,0}
};
int maxR, maxC, maxN,minN, minR,minC;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> a[2][i];
	}

	maxN = a[0][0];
	minN = a[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] > maxN) {
				maxN = a[i][j];
				maxR = i;
				maxC = j;
			}
			if (a[i][j] < minN) {
				minN = a[i][j];
				minR = i;
				minC = j;
			}
		}
	}

	cout << "MAX=" << maxN << "(" << maxR << "," << maxC << ")"<<'\n';
	cout << "MIN=" << minN << "(" << minR << "," << minC << ")";
	return 0;
}
