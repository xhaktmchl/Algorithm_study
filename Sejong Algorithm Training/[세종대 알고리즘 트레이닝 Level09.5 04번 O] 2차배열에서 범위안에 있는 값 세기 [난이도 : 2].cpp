#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 04번 O] 2차배열에서 범위안에 있는 값 세기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b;
int ar[5][5] = {
	{10,3,20},
	{60,31,40},
	{20,30,40}
};
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> a >> b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ar[i][j] >= a && ar[i][j] <= b) {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
