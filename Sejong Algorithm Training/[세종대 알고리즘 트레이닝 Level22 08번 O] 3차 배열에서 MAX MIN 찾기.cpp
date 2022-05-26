#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 08번 O] 3차 배열에서 MAX MIN 찾기
문제:
접근: 
풀이: 완탐
시간복잡도: O()=
*/
int a[5][5][5] = {
	{
		{2,4},
	{1,5}
},
{
	{2,3},
	{3,6}
},
{
	{7,3},
	{1,5}
}
};
int loc;
int maxN, minN;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> loc;
	//2.탐색
	maxN = a[loc][0][0];
	minN = a[loc][0][0];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			maxN = max(maxN, a[loc][i][j]);
			minN = min(minN, a[loc][i][j]);
		}
	}
	//3.출력
	cout << "MAX=" << maxN << '\n';
	cout << "MIN=" << minN;
	return 0;
}
