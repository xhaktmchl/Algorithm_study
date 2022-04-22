#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 07번] 마스킹 처리후의 입력값 존재 여부 O
문제:
접근:
풀이:
시간복잡도: O(n*n)=
*/
int check[5][10] = {
	{0,0,1,0,0},
	{0,0,1,1,1}
};
int a[5][10] = {
	{3,5,4,1,1},
	{3,5,2,5,6}
};
int num;
bool flag = false;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> num;
	//2.완탐: 마스킹 된 곳 타겟 숫자 있는지 탐색
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == 1) {
				if (a[i][j] == num) {
					flag = true;
					break;
				}
			}
		}if (flag == 1) { break; }
	}
	//3.출력
	if (flag) { cout << num << " 존재"; }
	else { cout << num << " 없음"; }
	return 0;
}
