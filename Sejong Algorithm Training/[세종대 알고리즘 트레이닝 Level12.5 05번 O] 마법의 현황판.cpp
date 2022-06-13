#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 05번 O] 마법의 현황판
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10][10] = {
	{4,5,4,5,4},
	{8,9,8,9,8},
	{1,2,1,2,1},
	{4,5,4,5,4},
	{6,7,6,7,6}
};
int r, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		cin >> r >> c;
		a[r][c] = (a[r][c]+1)%10;	
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j];
		}cout << '\n';
	}
	return 0;
}
