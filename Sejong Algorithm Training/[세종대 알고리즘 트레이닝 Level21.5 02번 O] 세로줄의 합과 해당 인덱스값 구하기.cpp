#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 02번 O] 세로줄의 합과 해당 인덱스값 구하기
문제:
접근: 
풀이: 
	//1.입력: 인덱스
	//2.배열의 합 구하기
	//3.출력: sum(idx)
시간복잡도: O()=
*/
int a[5][5] = {
	{3,4,1,5},
	{3,4,1,3},
	{5,2,3,6}
};
int idx, su =0;
int sum[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 인덱스
	cin >> idx;
	//2.배열의 합 구하기
	for (int i = 0; i < 4; i++) {
		su = 0;
		for (int j = 0; j < 3; j++) {
			su += a[j][i];
		}
		sum[i] = su;
	}
	//3.출력: sum(idx)
	cout << sum[idx];
	return 0;
}
