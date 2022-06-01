#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 01번 O] 3차배열과 문자의 발견여부
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 3차 배열 문자 있는지 탐색
	//3.출력
시간복잡도: O(2*2*3)=
*/
char a[5][5][5] = {
	{
		"ATB",
		"CCB"
},
	{
		"AAA",
		"BBC"
}
};
char tar;
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> tar;
	//2.완탐: 3차 배열 문자 있는지 탐색
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int p = 0; p < 3; p++) {
				if (a[i][j][p] == tar) { flag = 1; }
			}
		}
	}
	//3.출력
	if (flag == 1) { cout << "발견"; }
	else cout << "미발견";
	return 0;
}
