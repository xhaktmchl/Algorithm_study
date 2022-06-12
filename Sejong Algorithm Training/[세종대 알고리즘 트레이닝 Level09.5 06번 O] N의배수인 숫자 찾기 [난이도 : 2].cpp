#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 06번 O] N의배수인 숫자 찾기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[5][5] = {
	{3,5,14},
	{2,3,9},
	{6,2,7}
};
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] % n == 0) {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
