#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0623 O] 인접행렬 탐색 기본
접근:
풀이:

시간복잡도: O()=
*/
int ad[7][7] = {
	{0,0,1,1,1,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
};
char val[7] = "AEBCDF";
int node;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> node;
	
	for (int i = 0; i < 6; i++) {
		if (ad[node][i] == 1) {
			cout << ad[node][i] << " ";
		}
	}
	return 0;
}
