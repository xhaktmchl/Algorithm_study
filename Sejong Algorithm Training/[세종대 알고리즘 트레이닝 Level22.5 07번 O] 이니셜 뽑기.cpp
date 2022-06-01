#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 07번 O] 이니셜 뽑기
문제:
접근: 
풀이:
	//1.입력
	//2.정렬
	//3.출력
시간복잡도: O()=
*/
int ar[6][6][6] = {
	{
		{0,1,0},
{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1}
},
	{
		{1,1,1},
{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,1,1}

},
	{
		{1,1,1},
	{1,0,1},
	{1,0,0},
	{1,0,1},
	{1,1,1}
},
	{
		{1,1,0},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,0}
}

};
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.해당하는 삼차 배열 출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (ar[n][i][j] == 1) {
				cout << "#";
			}
			else { cout << " "; }
		}cout << '\n';
	}
	return 0;
}
