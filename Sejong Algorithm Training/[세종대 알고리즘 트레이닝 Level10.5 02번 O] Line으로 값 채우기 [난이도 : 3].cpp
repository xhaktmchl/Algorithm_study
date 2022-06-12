#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 02번 O] Line으로 값 채우기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10][10] = {
	{21,16,11,6,1},
	{22,17,12,7,2},
	{23,18,13,8,3},
	{24,19,14,9,4},
	{25,20,15,10,5}
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> n;
	//2.배열 행 채우기
	for (int i = 0; i < 5; i++) {
		a[n][i] = n;
	}
	//3.출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
